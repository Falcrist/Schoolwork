/*	Talen Phillips
	"Date Formats"
	11FEB2013
	Description: This program takes a date inputted by a user, and reformats it. */
#include <stdio.h> /* header file */
int main (void) /* only one function needed for this program */
{
	int y, m, d; /* defining variables */
	printf("Enter a date (mm/dd/yy):  "); /* displaying instructions to user */
	scanf("%i/%i/%i", &m, &d, &y); /* assigning user inputs to the above defined variables */
	printf("\nYou entered the date: 20%02i%02i%02i.\n", y, m, d); /* outputting the results with leading zeros if necessary */
	return 0; /* end of program */
}

