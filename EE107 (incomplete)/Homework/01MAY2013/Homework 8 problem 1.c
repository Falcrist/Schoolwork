#include <stdio.h>
int main(void)
{
	char s[]="Hsjodi"; // Each spot in the array contains a character of the word Grinch with it's value increased by 1.
	printf("%i\n",s[6]);
	char *p; // Initializing pointer.
	p=s; // References the pointer to the first element of the s array.
	while (*p){ // Stops the loop when it sees a null character (zero value).
        (*p)--; // Subtracts 1 from the value at address: *p.
        p++; // Points *p to the next address.
        }
	puts(s); // Prints the contents of the s array to the screen as a string.
	return 0;
}

