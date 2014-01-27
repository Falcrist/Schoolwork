#include <stdio.h>
#define ARR_LEN 30
int main(void) {
    char c, arr[ARR_LEN] = {0};
    int i, n, letters = 0, L = 0;
    while ((c = getchar()) != '\n'){
        if (c==' ' || c=='\t'){
            ++arr[letters];
            letters = 0;
        }
        else ++letters;
    }
    for (i=0; i<ARR_LEN; ++i)
        if (arr[i]>L)
            L = arr[i];
    for (;L>0;--L){
        printf("%4d |",L);
        for (i=0; i<ARR_LEN; ++i){
            if (arr[i]>=L)
                printf("  *");
            else printf("   ");
        }
        putchar('\n');
    }
    printf("-----|");
    for (i=0; i<ARR_LEN; ++i) printf("---");
    printf("\n     |");
    for (i=0; i<ARR_LEN; ++i) printf("%3d",i);
    return 0;
}
