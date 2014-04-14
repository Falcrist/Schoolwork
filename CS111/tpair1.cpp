//sat1.cpp -- Test copy constructor and destructor
// WITHOUT a copy constructor, the alteration in fiddle() will persist
// WITH a copy constructor, the alteration is only to a copy of mp
// Without destructor wind up with 2, With destructor get 1

#include <iostream>
#include <cstdlib>

#include "Pair2.h"

using namespace std;

void fiddle(Pair<string,int> x)
   {
      x.setFirst("Bethesda");
      x.setSecond(202);
      cout<<"In fiddle() pair count: "<<x.getPairCount()<<endl;
   }

int main(int argc, char *argv[])
   {
      Pair<string,int> mp("Dean",22);

      cout<<"Before: "<<mp.toString()<<"  Pair count: "<<mp.getPairCount()<<endl;
      fiddle(mp);
      cout<<"After:  "<<mp.toString()<<"  Pair count: "<<mp.getPairCount()<<endl;

   }
