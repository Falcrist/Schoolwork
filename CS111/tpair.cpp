// tpair.cpp
// test the basic Pair template

#include <iostream>
#include <cstdlib>

#include "Pair2.h"

using namespace std;

int main(int argc, char *argv[])
   {
      Pair<int,string> a,b(2,"Dean");

      cout<<"Initially"<<endl;
      cout<<"    a: "<<a.toString()<<"  b: "<<b.toString()<<endl;

      cout<<"    a using getters: (";
      if (a.getFirst()==NULL)
         cout<<"NULL";
      else
         cout<<(*a.getFirst());
      cout<<",";
      if ( a.getSecond() == NULL)
         cout<<"NULL";
      else
         cout<<(*a.getSecond());
      cout<<")"<<endl;

      a.setFirst(99);
      a.setSecond("Kelley");
      cout<<"\nAfter set a's values"<<endl;
      cout<<"    a: "<<a.toString()<<endl;

      cout<<"    a using getters: (";
      if (a.getFirst()==NULL)
         cout<<"NULL";
      else
         cout<<(*a.getFirst());
      cout<<",";
      if ( a.getSecond() == NULL)
         cout<<"NULL";
      else
         cout<<(*a.getSecond());
      cout<<")"<<endl;

      cout<<"There are "<<a.getPairCount()<<" pairs"<<endl;
   }
