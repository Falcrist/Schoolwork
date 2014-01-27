#include <stdio.h>
double fact_funct (int n);
double fact;
int main (void){
	int n;
	fact = 1;
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("fact = %g\n",fact_funct(n));
	return 0;
}
double fact_funct (int n){
	if (n>0){
		return fact = n * fact_funct(n-1);
	}
	else return fact;
}

