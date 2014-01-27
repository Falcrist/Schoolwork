#include <stdio.h>
main(){
    float fahr, celsius;
    int lower, upper, step;
    lower = -40;
    upper = 160;
    step = 20;
    celsius = lower;
    printf("  C \t F\n");
    while (celsius <= upper) {
        /*celsius = (5.0/9.0) * (fahr-32.0);*/
        fahr = (celsius*9.0/5.0)+32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
