#include <stdio.h>
#define MAXLINE 100

int getline(FILE *file_ptr, char line[], int maxline);
void copy(char to[], char from[]);
FILE *open_file();

int main(void)
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];
    FILE *file_ptr = open_file();

    max = 0;
    while ((len = getline(file_ptr, line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("The longest sentence is %d characters long:\n%s\n", max, longest);
    return 0;
}

int getline(FILE *file_ptr, char s[], int lim)
{
    int c = '.', i;

    for (i = 0; (c = fgetc(file_ptr)) != EOF && c != '.'; ++i)
        if (i < lim-1)
            s[i] = c;
    if (i < lim-1)
        s[i] = '\0';
    else
        s[lim] = '\0';

    return i;
}

void copy(char to[], char from[])
{
    int i;
    for (i = 0; (to[i] = from[i]) != '\0'; ++i);
    return;
}

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
