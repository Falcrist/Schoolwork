/* Talen Phillips
 * EE107-01
 * 08APR2013
 * "Even or Odd"
 */
#include <stdio.h>
/*declaring each additional function (since they come after the function in which they're called)*/
int fn_even(int i);
int fn_odd(int i);
int main (void){
    int i;
    printf("Enter a number: ");
    scanf("%d",&i);
    if ((i%2)==0) fn_even(i);
    else fn_odd(i);
    return 0;
}
/*defining each additional function*/
int fn_even(int i){
    printf("%i is even.\n",i);
    return 0;
}
int fn_odd(int i){
    printf("%i is odd.\n",i);
    return 0;
}

