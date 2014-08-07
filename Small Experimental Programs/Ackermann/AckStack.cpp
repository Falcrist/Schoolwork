#include <iostream>
#include "Pair.h"
#include "StackNode.h"
#include "Stack.h"
using namespace std;

int ack(int m, int n)
{
    Pair<int,int> top(m,n);
    Stack< Pair<int,int> > s;
    s.push(top);

    while (s.pop(top)) {
        if (*top.getFirst() == 0) {
			// Case 1: ack(0,x) = x+1
            int answer = *top.getSecond() + 1;
            while (*top.getSecond() != -1) // -1 used as a flag for unknown input (from case 3)
                if (!s.pop(top))
                    return answer; // successful completion happens here
            top.setSecond(answer); // flagged input filled in.
			s.push(top);
        }
        else if (*top.getSecond() == 0) {
        	// Case 2: ack(x,0) = ack(x-1, 1)
            Pair<int,int> x(*top.getFirst()-1, 1);
            s.push(x);
        }
        else {
        	// Case 3: ack(x,y) = ack(x-1, ack(x,y-1))
            Pair<int,int> x(*top.getFirst()-1, -1); // -1 flag used used to denote unknown input
            s.push(x);
            x.setFirst(*top.getFirst());
            x.setSecond(*top.getSecond() - 1);
            s.push(x);
		}

    }
    return 0; // Impossible to get here as far as I know.
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
