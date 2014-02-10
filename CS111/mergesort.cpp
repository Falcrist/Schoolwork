#include <iostream>
using namespace std;

string sortString(string s);

int main(void)
{
    string s = "1094285195671294756123908475612093847610298374516092874501657234764213678943678321768123470125768052314678905464312551234631254621354631254680351246831254612354615243665423756719427386446781567541736285176041056106923469102308376209834511230948172398041608791630985173049857230945723890465730948567312345678900987654321193514613546713546713547889354697315442356135467";
    s = sortString(s);
    cout << s << endl;
    return 0;
}
string sortString(string s)
{
    if (s.length() <= 1)
        return s;

    unsigned int i = 0;
    unsigned int j = 0;
    string a = "";
    string b = "";
    for (i = 0; i < s.length(); ++i){
        if ((i%2) == 0)
            a += s[i];
        else
            b += s[i];
    }
    a = sortString(a);
    b = sortString(b);
    s = "";
    i = j = 0;
    while (i < a.length() || j < b.length()) {
        if ((a[i] < b[j] && i < a.length()) || j >= b.length())
            s += a[i++];
        else
            s += b[j++];
    }
    return s;
}
