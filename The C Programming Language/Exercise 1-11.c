#include <stdio.h>
int main(void){
    char c;
    while ((c = getchar()) != '\n') {
            if (c == ' ') c = '\n';
            putchar(c);
    }
    return 0;
}
