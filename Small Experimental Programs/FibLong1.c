#include <stdio.h>
#include <float.h>
int main(void)
{
    int i = 0;
    for(double a=0,b=1; (b+=a)<DBL_MAX; a+=b, i+=2){
        printf("%10.3g%10.3g",a,b);
        if (!(i%11))
            putchar('\n');
    }
    printf("  Total = %d\n\n", i - 1);
}
