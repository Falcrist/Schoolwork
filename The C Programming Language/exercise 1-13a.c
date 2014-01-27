#include <stdio.h>
int main(void) {
    char c, arr[20] = {0};
    int i, n, letters = 0;
    while ((c=getchar())!='\n'){
        if ((c==' ')||(c=='\t')){
            ++arr[letters];
            letters = 0;
        }
        else ++letters;
    }
    for (i=0; i<20; ++i){
        for (n=0; n<arr[i]; ++n)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
