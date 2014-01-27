/* Lab2 Program 3: This program displays the minimum and maximum values for CHAR, INT, and LONG_INT variables. */

#include <stdio.h> /* These are the include files. */
#include <limits.h>

int main (void) /* The function doesn't do any operations, so it's void. */

{

/* Char variables are characters represented by a single, signed, 8-bit byte. The numeric limits are (2^7) - 1 and -(2^7). */
printf ("The numeric limit of CHAR_MIN is %d.\n",CHAR_MIN); /* This is the minimum value which can be stored in a char variable. */
printf ("The numeric limit of CHAR_MAX is %d.\n",CHAR_MAX); /* This is the maximum value which can be stored in a char variable.  */

/* Int variables are integer numbers that represent a signed, 4-byte binary number (each byte is 8 bits long). The numeric limits are (2^31) - 1 and -(2^31). */
printf ("The numeric limit of INT_MIN is %d.\n",INT_MIN); /* This is the minimum value which can be stored in an int variable. */
printf ("The numeric limit of INT_MAX is %d.\n",INT_MAX); /* This is the maximum value which can be stored in an int variable. */

/* Long Int variables are integer numbers that represent a signed, 4-byte binary number. On certain 64-bit platforms, they may be 8-bytes long. */
printf ("The numeric limit of LONG_MIN is %d.\n",LONG_MIN); /* This is the minimum value which can be stored in a long variable. */
printf ("The numeric limit of LONG_MAX is %d.\n",LONG_MAX); /* This is the maximum value which can be stored in a long variable. */

return 0;

}


