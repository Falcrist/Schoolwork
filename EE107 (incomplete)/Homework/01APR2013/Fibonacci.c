/* Talen Phillips
 * EE107-01
 * 01APR2013
 * "Fibonacci"
 */
#include <stdio.h>
int main (void)
{
	int i, fib_numbers[40]; //initialize i and a 1D, 40 variable array.
	/* this loop calculates the fibonacci numbers 1-40 and stores them
	 * in an array. If it attempts to continue, it will overflow the
	 * int variable at the 48th iteration.*/
	for (i = 0;i < 40;i++) {
		if ((i-2) < 0) fib_numbers[i] = i; //starts the sequence {0,1}
		else fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];
	}
	/* this loop displays the array in 5 columns.
	 * Note: all of the statements in brackets are the same as the
	 * previous loop. It would be easy to include this in the previous
	 * loop by copying the if and else statements.*/
	for (i = 0;i < 40;i++) {
		if (((i+1) % 5) != 0) printf("%8i ", fib_numbers[i]);
		else printf("%8i\n", fib_numbers[i]);
	}
	return 0;
}

