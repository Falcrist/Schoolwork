/* Talen Phillips
 * EE107-01
 * 29APR2013
 * "mean word length"
 */
#include <stdio.h>
/* declare the required function */
double compute_average_word_length(const char *sentence);
int main (void){
	int n; /* loop counter */
	char sen[101]; /* array to hold the sentence */
	char *sentence; /* pointer to manipulate the string */
	sentence = &sen[0]; /* pointing at object zero of the string */
	printf("Enter a sentence: \n");
	/* input using getchar (as required) and the pointer. */
	for (n=0; (n<100)&&(*(sentence-1)!='\n'); ++n){
		*sentence = getchar();
		++sentence;
	}
	*sentence = '\0'; /* adding null terminator */
	sentence = &sen[0]; /* resetting pointer */
	/* calling function, and printing result */
	printf("Mean word length is %g",compute_average_word_length(sentence));
	return 0;
}
double compute_average_word_length(const char *sentence){
	double words,letters;
	for (words=0,letters=0; *sentence!='\0'; ++sentence){
		/* If the current character isn't a letter and the previous one was,
		 * increment words. */
		if (((*sentence<'a' || *sentence>'z')&&(*sentence<'A' || *sentence>'Z')) && ((*(sentence-1)>='a' && *(sentence-1)<='z')||(*(sentence-1)>='A' && *(sentence-1)<='Z')))
			++words;
		/* Otherwise, if the current character is a letter, increment letters */
		else if ((*sentence>='a' && *sentence<='z') || (*sentence>='A' && *sentence<='Z'))
			++letters;
	}
	/*return the average*/
	return (letters/words);
}

