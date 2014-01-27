/* Lab2 Program: This program reads positive floating point numbers, and outputs them as floating point numbers with 4 digits of precision in a specified format. */

#include <stdio.h> /* These are the include files. */

int main (void) /* The function doesn't do any operations, so it's void. */

{

float my_number; /* This line describes format of the contents of the memory and specifies a label. */

scanf("%f",&my_number); /* This is our input. */

printf("%1.3fB    |%1.3f    %1.3f|\n%1.3fC    |         %1.3f|\n     %1.3f|ABC     A%1.3f|\n\n1234567891234567891234\n",my_number,my_number,my_number,my_number,my_number,my_number,my_number); /* This is our output. */

return 0;

}

