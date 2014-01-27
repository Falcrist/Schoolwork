#include <stdio.h>
int main(void){
    char c, d;
    while ((d = getchar()) == '\n') {
            if ((c != ' ')||(d != ' ')) {
                c = d;
                putchar(c);
            }
    }
    return 0;
}
