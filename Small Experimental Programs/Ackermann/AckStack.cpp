#include <iostream>
#include "Pair.h"
#include "StackNode.h"
#include "Stack.h"
using namespace std;

int ack(int m, int n) {
    Pair<int,int> top(m,n);
    Stack< Pair<int,int> > s;
    s.push(top);
    int i = 0;

    while (s.pop(top)) {
        if (*top.getFirst() == 0) {
			//cout << "Case 1: " << *top.getFirst() << ',' << *top.getSecond() << endl;
            int answer = *top.getSecond() + 1;
            while (*top.getSecond() != -1)
                if (!s.pop(top))
                    return answer;
            top.setSecond(answer);
			s.push(top);
        }
        else if (*top.getSecond() == 0) {
        	//cout << "Case 2: " << *top.getFirst() << ',' << *top.getSecond() << endl;
            Pair<int,int> x(*top.getFirst()-1, 1);
            s.push(x);
        }
        else {
        	//cout << "Case 3: " << *top.getFirst() << ',' << *top.getSecond() << endl;
            Pair<int,int> x(*top.getFirst()-1, -1);
            s.push(x);
            x.setFirst(*top.getFirst());
            x.setSecond(*top.getSecond() - 1);
            s.push(x);
		}
		if (++i == 1000000) {
			cout << *top.getFirst() << ',' << *top.getSecond() << endl;
			i = 0;
		}

    }
    return 0; // MOTHER F@#$ING FAILURE, SON! Process never gets here.
}

int main(void)
{
	int m, n;
	cout << "Enter first number:" << endl;
	cin >> m;
	cout << "Enter second number:" << endl;
	cin >> n;
	cout << "ackermann (" << m << ',' << n << ") is: " << ack(m,n) << endl;
	return 0;
}
