#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
    double pi = 3;
    int neg = 1;
    double denom = 2;
    int i = 0;
    while (i++ < 70000){
        pi += (4 * neg) / (denom * (denom+1) * (denom+2));
        neg = -neg;
        denom+=2;
    }
    cout << setprecision(16) << pi << endl;
    return 0;
}
