#include <stdio.h>
#include <conio.h>
void PowersOfTen (int n)
{
	short i = 1;
	int p = 1;
	while (i <= n)
	{
		p = p * 10;
		i++;
	}
	printf ("10 to the power of %2i is:%10i.\n", n, p);
	return;
}
int main (void)
{
	short j = 0;
	while (j <= 6)
	{
		PowersOfTen (j);
		j++;
	}
	getch();
	return 0;
}

