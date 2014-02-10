#include <iostream>
#include <string.h>
using namespace std;

void sortString(char *first, char *last);

int main(void)
{
    char s[] = "1094285195671294756123908475612093847610298374516092874501657234764213678943678321768123470125768052314678905464312551234631254621354631254680351246831254612354615243665423756719427386446781567541736285176041056106923469102308376209834511230948172398041608791630985173049857230945723890465730948567312345678900987654321193514613546713546713547889354697315442356135467";
    sortString(&s[0], &s[strlen(s) - 2]);
    cout << s << endl;
    return 0;
}

void sortString(char *first, char *last)
{
    if ((*last - *first) <= 1)
        return;
    char *pivot = 0;
    *pivot = (*last + *first) / 2;
    sortString(first, pivot);
    sortString(pivot + 1, last);
    char *i = first;
    char *j = pivot + 1;
    string s = "";
    while (i <= pivot || j < last){
        if ((&i > &j) && i <= pivot){
            s += *i;
            ++i;
        }
        else {
            s += *j;
            ++j;
        }
    }

}
