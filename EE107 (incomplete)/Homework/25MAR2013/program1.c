/* Talen Phillips
 * EE107-01
 * 25MAR2013
 * "Largest Number"
 */
#include <stdio.h>
int main (void)
{
	float input,largest;
	do{
		printf("Enter a number: ");
		scanf("%f",&input);
		if (input > largest) largest = input;
		// Each input is compared to the current largest
	}while (input > 0); // Loop ends when input is 0
	printf("The largest number entered was %g\n",largest);
	// NOTE: %g was used to drop the trailing zeros.
	return 0;
}

