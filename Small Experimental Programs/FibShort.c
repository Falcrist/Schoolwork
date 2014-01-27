#include <stdio.h>
int main(void){
    for(int a=0,b=1; (b+=a) > 0; a+=b)
        printf("%d, %d, ",a,b);
}
