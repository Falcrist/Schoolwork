/* Talen Phillips
 * EE107-01
 * 01APR2013
 * "Sentence"
 */
#include <stdio.h>
int main (void)
{
    int i;
	char sen[81];
	printf("Enter a sentence:\n");
	fgets(sen,81,stdin);
	for (i=0; sen[i]!='\0'; i++){
		if (((i==0)||(sen[i-1]==' '))&&(sen[i]>='a')&&(sen[i]<='z')) putchar(sen[i]-32);
		else putchar(sen[i]);
	}
	return 0;
}

