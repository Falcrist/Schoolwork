#include <stdio.h>
int main(void){
    int c, blanks=0, tabs=0, spaces=0;
    while ((c = getchar()) != '\n') {
            if (c == '\t')
                ++tabs;
            if (c == ' ')
                ++spaces;
            putchar(c);
    }
    blanks = tabs + spaces;
    printf("\n\ntabs = %d\nspaces = %d\nblanks = %d", tabs, spaces, blanks);
    return 0;
}
