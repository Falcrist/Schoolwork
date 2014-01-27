#include <stdio.h>
int main (void)
	{
	int year,month,day,hour,minute,second,input;
	int x = 1;
	while (x == 1){
	printf("Enter a unix time\n");
	scanf("%d",&input);
	second = input % 60;
	minute = input  % 3600;
	hour = input % 86400;
	day = input % 2678400;
	month = input % 32140800;
	year = input / 32140800;
	printf("\n%i months %i days, and %i years.\n",month,day,year);
	printf("The time is %i:%i and %i seconds.\n",hour,minute,second);
	x = 1;
	printf("\nPress 1 to continue.  ");
	scanf("%i",&x);
	}
	return 0;
	}

