/* Talen Phillips
 * EE107-01
 * 25MAR2013
 * "e Calculator"
 */
#include <stdio.h>
int main (void)
{
	int n,x;
	double result = 1;
	double fact = 1;
	printf("Enter a number: ");
	scanf("%d",&x);
	for (n=1;n<=x;n++){
		fact *= n; //increment factorial
		result += (1.0/fact);//add 1/fact to the total
	}
	printf("e = %.16g\n",result);
	return 0;
}

