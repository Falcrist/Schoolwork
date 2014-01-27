#include <stdio.h>
int main (void){
/*char s1[]="computer";
char s2[]="science";*/
char s1[9],s2[8];
strcpy(s1, "computer");
strcpy(s2, "science");
if (strcmp(s1,s2) < 0)strcat(s1,s2);
else strcat(s2,s1);
printf("%i\n",strlen(s1)-6);
s1[strlen(s1)-6] = '\0';
printf("%s",s1);
return 0;
}
