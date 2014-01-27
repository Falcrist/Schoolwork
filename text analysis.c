/* "TXT Analyser" by Talen Phillips
 * written on 23MAY2013
 * This program analyses a file of ASCII text, and prints out stats and graphs.
 * It was originally written as an exercise (K&R2: 1-13 and 1-14), but became an
 * exploratory project. */

#include <stdio.h>
#define MAX_LENGTH 13
#define MAX_HEIGHT 15
#define MAXLINE 1000
#define IN 1
#define OUT 0

void stats(void);
void analyze(FILE *temp_ptr, int word_lengths[], int letter_frequency[]);
FILE *open_file();
void print_table(int arr[], int arr_len);
int longest_sen(FILE *file_ptr, char line[], int maxline);
void copy(char to[], char from[]);

/**********************************  MAIN  **********************************/
int main(void)
{
	char cont = 'N', c;
	do {
		stats();
		printf("\nContinue? Y/N   ");
		while ((c = getchar()) != '\n' && c != EOF)
			cont = c;
		putchar('\n');
	} while (cont == 'Y' || cont == 'y');
	return 0;
}

/****************************** STATS FUNCTION ******************************/
void stats(void)
{
	FILE *file_ptr;
	int i, len, max, word_lengths[MAX_LENGTH] = {0}, letter_frequency[26] = {0};
    char c, filename[200]= {0}, line[MAXLINE], longest[MAXLINE];

    /* Open file and return pointer. Exit to main if there's an error. */
    printf("Enter the name (with path) of a text file:    ");
	for (i = 0; (c = getchar()) != '\n' && i < 200; ++i)
		filename[i] = c;
	putchar('\n');
	file_ptr = fopen(filename,"r");
	if (file_ptr == NULL){
        perror("Error opening file");
        return;
	}

	analyze(file_ptr, word_lengths, letter_frequency);

	/***** Table 1: Word Length Histogram *****/
	printf(" Table:     Word Lengths\n------------------------\n");
	print_table(word_lengths+1, MAX_LENGTH-1);
	/* Print horizontal axis legend: */
	printf("\n       |");
	for (i = 1; i < (MAX_LENGTH-1); ++i) {
		if (!(i % 5))
			printf("%2d", i);
		else
			printf("  ");
	}
	printf(" +\n\n");


	/***** Table 2: Letter Frequency Histogram *****/
	printf(" Table:   Letter Frequency\n--------------------------\n");
	print_table(letter_frequency, 26);
	/* Print horizontal axis legend: */
	printf("\n       |");
	for (i = 0; i < 26; ++i)
		printf(" %c", i + 65);
	printf("\n\n");

    /* Re-initialize file pointer */
	file_ptr = fopen(filename,"r");
	if (file_ptr == NULL){
        perror("Error opening file");
        return;
	}

    /* Find the longest sentence, and print the longest one. */
    max = 0;
    while ((len = longest_sen(file_ptr, line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("The longest sentence is %d characters long:\n%s. \n\n", max, longest);
    else printf("The longest sentence is: 0 \n\n");

    fclose(file_ptr);

	return;
}

/***************************** ANALYZE FUNCTION *****************************/
/* Fills the arrays declared in stats() and prints out general statistics. */
void analyze(FILE *temp_ptr, int word_lengths[], int letter_frequency[])
{
	char c, state = OUT;
	int num_word = 0, num_sen = 0, num_let = 0, num_char = 0, word_len = 0;

	/* Count each word and increment the corresponding array element.
	 * This loop also contains char, letter, word, and sentence counters.*/
	while ((c = fgetc(temp_ptr)) != EOF) {
		if (c == '.') /* (need better definition of sentence) */
			++num_sen;
		else if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
			if (word_len >= MAX_LENGTH) ++word_lengths[MAX_LENGTH-1];
			else ++word_lengths[word_len];
			word_len = 0;
		}
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			if (c >= 'a' && c <= 'z')
				++letter_frequency[c-97];
			else
				++letter_frequency[c-65];
			if (state == OUT) {
				state = IN;
				++num_word;
			}
		++num_let;
		++word_len;
		}
	++num_char;
	}

	/****************** Print totals and averages ******************/
	printf("Number of characters: %d\n",num_char);
	printf("Number of letters:    %d\n",num_let);
	printf("Number of words:      %d\n",num_word);
	printf("Number of sentences:  %d\n\n",num_sen);
	printf("Mean word length:     %.2f letters\n",1.0*num_let/num_word);
	printf("Mean sentence length: %.2f words\n\n",1.0*num_word/num_sen);

	return;
}

/**************************** OPEN_FILE FUNCTION ****************************/
/* Open file and return the FILE pointer. Display message if error occurs. */
FILE *open_file()
{
	char c, filename[200]= {0};
	int i;
	FILE *file_ptr;

	printf("Enter a file name:    ");
	for (i = 0; (c = getchar()) != '\n' && i < 200; ++i)
		filename[i] = c;
	putchar('\n');
	file_ptr = fopen(filename,"r");

	if (file_ptr == NULL)
		perror("Error opening file");

	return file_ptr;
}

/*************************** PRINT_TABLE FUNCTION ***************************/
/* Print a vertical bar graph. Doesn't include horizontal axis legend. */
void print_table(int arr[], int arr_len)
{
	int i, big = 0, div = 1;

	/* find the largest element. */
	for (i = 0; i < arr_len; ++i)
		if (arr[i] > big)
			big = arr[i];

	/* Find a divisor */
	if (big > MAX_HEIGHT)
		div = big/MAX_HEIGHT;

	/* Scale each element such that: largest element <= MAX_HEIGHT */
	for (i = 0; i < arr_len; ++i)
		arr[i] /= div;
	big /= div;

	/* Print the vertical axis and the bars */
	for (; big > 0; --big) {
		printf("%6d |", big * div);
		for (i = 0; i < arr_len; ++i) {
			if (arr[i] >= big)
				printf(" *");
			else
				printf("  ");
		}
		putchar('\n');
	}

	/* Print horizontal axis (line only) */
	printf("-------|");
	for (i = 0; i < arr_len; ++i)
		printf("--");

	return;
}

/*************************** LONGEST_SEN FUNCTION ***************************/
/* Looks at each sentence, determines its length, stores it in the line
 * array from the stats function, and returns it's length. */
int longest_sen(FILE *file_ptr, char s[], int lim)
{
    int c = '.', i;

    for (i = 0; i < lim-1 && (c = fgetc(file_ptr)) != EOF && c != '.'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/**************************** COPY FUNCTION ****************************/
/* Copies from the line "array" to the "longest" array */
void copy(char to[], char from[])
{
    int i;
    for (i = 0; (to[i] = from[i]) != '\0'; ++i);
    return;
}
