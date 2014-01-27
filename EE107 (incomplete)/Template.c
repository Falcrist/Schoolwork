/* Talen Phillips
 * EE107-01
 * DATE
 * "Fibonacci"
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (void)
{
	int i,j,n;
	int hours = 24;
	int days = 30;
	double sum;
	srand (time(NULL));
	float temperature_matrix[30][24];
	for (i=0; i<30; i++)
	{
		for (j=0; j<24; j++)
		{
			temperature_matrix[i][j] = (rand() %50 + 200) * 0.1;
		}
	}
	for (i=0; i<30; i++)
	{
		if (i==0){
			printf("TempC|| 1am| 2am| 3am| 4am| 5am| 6am| 7am| 8am| 9am|10am|11am|12am| 1pm| 2pm| 3pm| 4pm| 5pm| 6pm| 7pm| 8pm| 9pm|10pm|11pm|12pm\n");
			printf("======||====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====|====\n");
			printf("%4i  |",i+1);
		}
		else {
			printf("------||----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----\n");
			printf("%4i  |",i+1);
		}
		for (j=0; j<24; j++) printf("|%4.1f", temperature_matrix[i][j]);
		putchar('\n');
	}
	for (i=0; i<30; i++)
	{
		for (j=0; j<24; j++) sum += temperature_matrix[i][j];
	}
	printf("\n\nThe average temperature is %f Celcius\n",sum/(days*hours));
	return 0;
}

