/* Talen Phillips
 * EE107-01
 * 01APR2013
 * "Sentence"
 */
#include <stdio.h>
int main (void){
char let, sen[81];
puts("Enter a sentence:\n");
fgets(sen,81,stdin);
for (int i=0; sen[i]!='\0'; i++) putchar(((sen[i-1]==' ')||((i-1)<0)&&(sen[i]>='a')&&(sen[i]<='z'))?sen[i]-32:sen[i]);
}

