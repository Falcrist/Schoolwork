/* Talen Phillips
 * EE107-01
 * 01APR2013
 * "Name"
 */
#include <stdio.h>
int main (void)
{
	char first[20];
	char last[20];
	printf("Enter a name: ");
	/* as mentioned in the answer to question 4, the
	 * scanf() function seems to treat each word as a
	 * separate string. */
	scanf("%s %s",first,last);
	/* this loop just prints the last name. SEE NOTE! */
	for (int i=0; last[i]!='\0'; i++) putchar(last[i]);
	printf(", ");
	/* this putchar just prints the first letter of the
	 * first name. */
	putchar(first[0]);
	putchar('.');
	return 0;
} 

