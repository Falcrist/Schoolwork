/* Talen Phillips
 * EE107-01
 * 29APR2013
 * "Extension array"
 */
#include <stdio.h>
/* max extension length +2 (for period and null terminator)*/
#define EXT_MAX 6
/* declare the get_extension function */
void get_extension(const char * file_name, char *extension);
int main (void){
    /* the "name" array is declared with a specific name for
	 * demonstration purposes. */
	char name[]="memo.txt";
	/* declaring the array that will hold the extension */
    char ext[EXT_MAX];
	/* setting both pointers to the first element of the
	 * respective arrays */
    char *file_name = &name[0];
    char *extension = &ext[0];
	/* function call */
    get_extension(file_name, extension);
	/* output the ext array for demonstration */
	puts(ext);
    return 0;
}
void get_extension(const char *file_name, char *extension){
    /* Unless I specifically tell the last loop to stop at
	 * the end of the array, it will overrun, and begin
	 * writing into memory directly adjacent to the array.*/
	int i;
	/* The first loop sets the file_name pointer to the
	 * period at the beginning of the extension */
	while(*file_name!='.') ++file_name;
	/* The second loop copies the data from the name array
	 * into the ext array. Note the use of i for safety. */
    for(i=0; (*file_name!='\0')&&(i<EXT_MAX-1); ++i){
        *extension=*file_name;
        ++extension;
        ++file_name;
    }
	*extension='\0'; /* set the null terminator */
    return;
}

