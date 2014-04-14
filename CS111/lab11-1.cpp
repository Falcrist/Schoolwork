// lab11-1.cpp
// count character frequencies from a file


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>                     // probably useful...

#include "Pair2.h"                      // uncomment for Part 2


using namespace std;

string getUserInput(string prompt)
   {
      string t="";
      cout<<prompt;
      getline(cin,t);
      return t;
   }

void errorMsg(string msg, bool term)
   {
      cout<<msg;
      if (term)
         exit(0);
   }



void dumpResults(int f[], string msg)
   {
      cout << msg << endl;
      for (int i=0;i<128;i++)
		 if (i < 32 && f[i])
			cout << '<' << i << '>' <<" -- "<<f[i]<<endl;
         else if (f[i])
			cout << '\'' << ((char)i) << '\'' << " -- " << f[i] << endl;
   }


int *getCharFreqs(ifstream &infile)
   {
		int *arr = NULL;
		arr = new int [128];
		for (int i = 0; i < 128; i++)
			arr[i] = 0;
		for (char c = 0; infile.get(c); arr[(int)c]++)
			;
		return arr;
   }
            
Pair<string,int> *makeResultsArray(int *freqs,int &n)
	{
		for (int i = 0; i < 128; i++)
			if (freqs[i])
				n++;
		Pair<string,int> *r = new Pair<string,int>[n];
		for (int i = 0, j = 0; i < 128; i++)
			if (freqs[i]) {
				stringstream ss;
				if (i < 32)
					ss << '<' << i << '>' << ' ';
				else
					ss << '\'' << ((char)i) << "\' ";
				r[j].setFirst(ss.str());
				r[j].setSecond(freqs[i]);
				j++;
		}
		return r;
	}

int main(int argc, char *argv[])
   {
      string filename = getUserInput("Filename: ");
      ifstream infile(filename.c_str());
      if (!infile)
         errorMsg("File doesn't exist...terminating",true);

      int *freqs = getCharFreqs(infile);

      infile.close();

      //dumpResults(freqs,"Here are the results");

//-----  Part 2 --------------------------------------------------------
	int n=0;
	Pair<string,int> *results = makeResultsArray(freqs,n);
	cout<<"n = "<<n<<endl;
	
	for (int i = 0; i < n; i++)
		cout << results[i].toString() << endl;
//-----
     return 0; 
   }
