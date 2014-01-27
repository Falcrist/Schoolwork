#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
int x;
srand (time(NULL));
x = rand() %10;
printf("random number %i",x);
}

