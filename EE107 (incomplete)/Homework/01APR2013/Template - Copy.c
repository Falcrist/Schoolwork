/* Talen Phillips
 * EE107-01
 * DATE
 * "temperature"
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* I've included these define statements to make the code easier to practice the define
 * statement, and to make it easier for someone with the source to edit the code. It may
 * also be slightly more readable. */
#define tot_days 30
#define tot_hours 24
int main (void)
{
	int hour;
	int day;
	float sum;
	srand (time(NULL));

	/* This is the definition of the array. */
	float temperature_matrix[tot_hours][tot_days];

	/* This first set of loops fills the array with numbers from 20.0 to 25.0.
	 * The outer loop increments the days, while the inner loop increments the hours
	 * and applies each randomly generated number to each position in the array.*/
	for (day=0; day<tot_days; day++){
		for (hour=0; hour<tot_hours; hour++){
			temperature_matrix[hour][day] = (rand() %50 + 200) * 0.1;
		}
	}
	
	/* This second set of loops prints the entire array to the screen with some nifty
	 * formatting that creates a grid that contains the numbers, and the days and hours.*/
	for (day=0; day<tot_days; day++){
		/* If we're at the beginning of the array, print the header */
		if (day==0) printf("TempC || 1am| 2am| 3am| 4am| 5am| 6am| 7am| 8am| 9am|10am|11am|12am| 1pm| 2pm| 3pm| 4pm| 5pm| 6pm| 7pm| 8pm| 9pm|10pm|11pm|12pm\n======||====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====\n");
		/* If we're not at the beginning of the array, print the horizontal divider. */
		else printf("------||----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----\n");
		/* at the beginning of each row, print the day.*/
		printf("%4i  |",day+1);
		/* This inner for loop prints the temp at each position in the array*/
		for (hour=0; hour<tot_hours; hour++) printf("|%4.1f", temperature_matrix[hour][day]);
		/* at the end of the row, put a newline */
		putchar('\n');
	}
	
	/* this final loop sums all of the values in the array */
	for (day=0; day<tot_days; day++){
		for (hour=0; hour<tot_hours; hour++) sum += temperature_matrix[hour][day];
	}
	/* finally, we use the sum to find the average of the entire array, and print it */
	printf("\n\nThe average temperature is %f Celcius.\n",sum/(tot_days*tot_hours));
	return 0;
}

