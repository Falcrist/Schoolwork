/* Talen Phillips
 * EE107-01
 * 08APR2013
 * "Decimal to Binary Converter"
 */
#include <stdio.h>
int main (void)
{
	printf("%i",sizeof(unsigned short int)*4 - 1);
	unsigned short int dec_num, i;
	unsigned short int bin_num = 1 << (sizeof(unsigned short int)*4 - 1);
	printf("Enter a decimal number between 1 and 255: ");
	scanf("%d",&dec_num);
	printf("The binary version of your number is:\t  ");
	for(i=0; i<sizeof(short int)*4; i++){
		printf("%hu",(dec_num & (bin_num >> i))!=0);
	}
	return 0;
}

