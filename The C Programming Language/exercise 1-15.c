#include <stdio.h>

int ftoc(int fahr);

int main(void)
{
    int fahr;
    for (fahr = 0; fahr <= 10000; fahr += 20)
        printf("%d\t%d\n", fahr, ftoc(fahr));
    return 0;
}

int ftoc(int fahr)
{
    return 5 * (fahr-32) / 9;
}
