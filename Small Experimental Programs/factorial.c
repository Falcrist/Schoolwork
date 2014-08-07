#include <stdio.h>
int main (void){
	int n;
	int i = 1;
	double fact = 1;

	printf("Enter a number: ");
	scanf("%d",&n);

	while (i <= n) {
		fact = fact * i;
		i = i + 1;
	}

	printf("\n fact = %g \n i = %i \n n = %i \n",fact,i,n);

	return 0;
}

