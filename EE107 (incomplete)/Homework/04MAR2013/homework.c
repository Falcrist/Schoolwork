/* Talen Phillips
 * EE107-01
 * 04MAR2013
 * "Digit Counter"
 */
#include <stdio.h>

int main(void)
{
	int n;
	short int cnt=1;
	printf("Enter a number:\n");
	scanf("%i", &n);
	// Since the input is altered, it needs to be printed first:
	printf("The number %i has", n);
	// This is an absolute value function to avoid issues with negative numbers:
	if (n<0) n=-n;
	// This loop divides by 10 until the value is 10 or less and counts the iterations.
	while (n>=10)
	{
		n = n / 10;
		cnt++;
	}
	printf(" %i digits.\n", cnt);
	return 0;
}

