#include <stdio.h>
void PowersOfTen (int n)
{
	double p = 1;
	short i = 1;
	while (i <= n)
	{
		p = p * 10;
		i++;
	}
	printf ("10 to the power of %2i is:%120.0f.\n", n, p);
	return;
}
int main (void)
{
	char x = 'y';
	while (x == 'y')
	{
		int j = 1, i;
		printf ("Enter a number between 0 and 22. ");
		scanf ("%i", &i);
		printf ("\n");
		PowersOfTen (0);
		while (j <= i)
		{
			PowersOfTen (j);
			j++;
		}
		printf ("\nPress Y to continue. ");
		scanf ("%s", &x);
		printf ("\n");
	}
	return 0;
}

