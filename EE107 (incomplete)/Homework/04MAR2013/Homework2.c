/* Talen Phillips
 * EE107-01
 * 04MAR2013
 * "Tax Calculator"
 */
#include <stdio.h>
int main (void){
	int income;
	printf("Enter your income:\n");
	scanf("%d", &income);
	// Each of the following if statements represents one of the tax brackets.
	// Each statement executes a printf that contains the equation for that bracket.
	if (income < 0) printf("Income cannot be negative!\nTax due: $0.00");
	if ((income >= 0) && (income < 750)) printf("Tax due: $%0.2f", income * 0.01);
	if ((income >= 750) && (income < 2250)) printf("Tax due: $%0.2f", 7.5 + (income-750) * 0.02);
	if ((income >= 2250) && (income < 3750)) printf("Tax due: $%0.2f", 37.5 + (income-2250) * 0.03);
	if ((income >= 3750) && (income < 5250)) printf("Tax due: $%0.2f", 82.5 + (income-3750) * 0.04);
	if ((income >= 5250) && (income < 7000)) printf("Tax due: $%0.2f", 142.5 + (income-5250) * 0.05);
	if (income >= 7000) printf("Tax due: $%0.2f", 230 + (income-7000) * 0.06);
return 0;
}
	

