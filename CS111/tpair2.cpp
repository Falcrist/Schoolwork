//sat2.cpp -- test operator=
// without it, or without it written correctly, the change to mp will be reflected
//   in np in the output.  A segfault will also occur when trying to destruct one
//   of the two because they are the same!

#include <iostream>
#include <cstdlib>

#include "Pair2.h"

using namespace std;

int main(int argc, char *argv[])
   {
      Pair<string,int> mp("Dean",22), np("Ann",23);           // two Pairs
      cout<<"Initially mp: "<<mp.toString()<<"  np: "<<np.toString()<<endl;

      np = mp;
      cout<<"After assignment mp: "<<mp.toString()<<"  np: "<<np.toString()<<endl;

      mp.setSecond(99);
      mp.setFirst("BillyBob");
      cout<<"After setSecond() mp: "<<mp.toString()<<"  np: "<<np.toString()<<endl;

   }
