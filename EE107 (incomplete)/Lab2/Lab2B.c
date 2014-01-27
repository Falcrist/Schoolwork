/* Lab2 Program 2: This program reads a character, and prints the hexidecimal value of the ASCII equivelant. */

#include <stdio.h> /* These are the include files. */

int main (void) /* The function doesn't do any operations, so it's void. */

{

char my_char; /* This line describes format of the contents of the memory and specifies a label. */

scanf("%c",&my_char); /* This is our input. */

printf("The ASCII equivelant of %c is %#x.\n",my_char,my_char); /* This is our output. */

return 0;

}


