#include <stdio.h>
int main (void)
{
	int n,d,L,gcd;
/* n is the numerator,
 * d is the denominator,
 * L is the largest of those two, and
 * gcd is the greatest common denominator
 */
//first take the input.
	printf("Enter a fraction: ");
	scanf("%d/%d",&n,&d);
//then find the larger number:
	L = d>n?d:n;
//then find the greatest common denominator:
	for (gcd=L;gcd>=1;gcd--)
		if ((n % gcd == 0) && (d % gcd == 0))break;
//then display the reduced fraction:
	if ((d/gcd) > 1)
		printf("in lowest terms: %i/%i\n",n/gcd,d/gcd);
//if denominator/gcd is 1, only display numerator/gcd:
	if ((d/gcd) == 1)
		printf("in lowest terms: %i\n",n/gcd);
	return 0;
}

