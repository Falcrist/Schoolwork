// lab9d2.cpp
// test Minmaxpair.h class template on doubles

#include <iostream>
#include <cstdlib>

#include "Minmaxpair.h"

using namespace std;

int main(int argc, char *argv[])
   {
      Minmaxpair<double> p1, p2(5.5,1.0);

      cout<<p2.toString()<<endl;

      p1.setFirst(9.9);
      p1.setSecond(-9.9);
      cout<<p1.toString()<<endl;

      cout<<"Max: "<<p2.getMax()<<endl;
      cout<<"Min: "<<p2.getMin()<<endl;
   }
