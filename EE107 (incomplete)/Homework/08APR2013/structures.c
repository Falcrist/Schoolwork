/* Talen Phillips
 * EE107-01
 * 08APR2013
 * "Structures"
 */
#include <stdio.h>
int main (void){
    int i;
	/*initialize structure*/
    struct A
    {
        int sign;
        int hundreds;
        int tens;
        int ones;
    };
    struct A number;
    printf("Enter a number from -999 to 999:  ");
    scanf("%d",&i);
    /*absolute value function, which also adjusts the sign*/
	if (i<0){
    i=-i;
    number.sign = 1;
    }
	else number.sign = 0;
	/*determine the value of each place*/
    number.hundreds = (i/100)%10;
    number.tens = (i/10)%10;
    number.ones = i%10;
	/* print the resultant values (included for bug detection).*/
    printf("%i %i%i%i",number.sign,number.hundreds,number.tens,number.ones);
}

