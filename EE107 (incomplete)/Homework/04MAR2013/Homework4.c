/* Talen Phillips
 * EE107-01
 * 04MAR2013
 * "Date Sorter"
 */
#include <stdio.h>
int main (void){
	int m1, d1, y1, m2, d2, y2, date1, date2; // The date1 and date2 variables are used for comparison.
	printf("Enter first date (mm/dd/yy): "); // Nothing is stopping the user from using a 4 digit year.
	scanf("%d/%d/%d", &m1, &d1, &y1);
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d", &m2, &d2, &y2);
	// The following two lines convert dates into one unit (days) for comparison.
	date1 = d1 + (31 * m1) + (365 * y1);
	date2 = d2 + (31 * m2) + (365 * y2);
	// The following if statements compare the dates and print the one with the higher value.
	if (date1 < date2) printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d.", m1, d1, y1, m2, d2, y2);
	if (date2 < date1) printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d.", m2, d2, y2, m1, d1, y1);
	if (date2 == date1) printf("These dates are the same!");
	return 0;
/* Note: If a two digit year is used, the program assumes that both dates will be during the same century.
 * If a 4 digit year is entered, the output will also include 4 digit years. */
}

