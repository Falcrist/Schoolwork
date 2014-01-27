#include <stdio.h>
#define PI 3.14159
#define MAX_I 1000

int main (void)
{
double x,y=-1.0; 
int a=3,b=4,i;
i = a % b;
printf("a) i = a %% b\nis valid, and the result is i = %i\n\n",i);
i = (989 - MAX_I) / a; 
printf("b) i = (989 - MAX_I) / a\nis valid, and the result is i = %i\n\n",i);
i = b % a;
printf("c) i = b %% a\nis valid, and the result is i = %i\n\n",i);
x = PI * y;
printf("d) x = PI * y\nis valid, and the result is i = %f\n\n",x);
i = a / -b;
printf("e) i = a / -b\nis valid, and the result is i = %i\n\n",i);
x = a / b;
printf("f) x = a / b\nis valid, and the result is i = %f\n\n",x);
printf("g) x = a %% (a / b)\nis not valid.\n\n");
printf("h) i = b / 0\nis not valid. It attempts to divide by zero\n\n");
i = a % (990 - MAX_I) / a;
printf("i) i = a %% (990 - MAX_I) / a\nis valid, and the result is i = %i\n\n",i);
return 0;
}

