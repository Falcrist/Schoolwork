#include <stdio.h>
int main (void){
int n, i;
double fact = 1;
printf("Enter a number: ");
scanf("%d",&n);
for (i=1; i<=n; ++i) fact *= i;
printf("\n fact = %g \n i = %i \n n = %i \n",fact,i,n);
return 0;
}

