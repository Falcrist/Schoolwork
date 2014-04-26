#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Pair.h"
#include "BinHeap.h"

using namespace std;

string getUserInput(string prompt);
void errorMsg(string msg, bool term);
int *getCharFreqs(ifstream &infile);
void dumpResults(int f[], string msg);
Pair<string,int> *makeResultsArray(int *freqs,int &n);

int main(int argc, char *argv[])
   {
      string filename = getUserInput("Filename: ");
      ifstream infile(filename.c_str());
      if (!infile)
         errorMsg("File doesn't exist...terminating",true);

      int *freqs = getCharFreqs(infile);

      infile.close();

	int n=0;
	Pair<string,int> *results = makeResultsArray(freqs,n);
	BinHeap< Pair<string,int> > bh(results,n);

	cout<<"n = "<<n<<endl;

    Pair<string,int> a, b;
    string s;
    string astr;
    string bstr;

    while (bh.size() > 1) {
        s = "";
        a = bh.getMin();
        astr = *(a.getFirst());
        for (unsigned int i = 0; i < astr.length(); i++) {
            if (astr[i-2] == '-')
                s += '1';
            s += astr[i];
        }

        b = bh.getMin();
        bstr = *b.getFirst();
        for (unsigned int i = 0; i < bstr.length(); i++) {
            if (bstr[i-2] == '-')
                s += '0';;
            s += bstr[i];
        }
        a.setFirst(s);
        int total = *a.getSecond() + *b.getSecond();

        a.setSecond(total);
        bh.insert(a);
    }
    cout << *(bh.getMin().getFirst()) << endl;
     return 0;
   }

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

void dumpResults(int f[], string msg)
   {
      cout << msg << endl;
      for (int i=0;i<128;i++)
		 if (i < 32 && f[i])
			cout << '<' << i << '>' <<" -- "<<f[i]<<endl;
         else if (f[i])
			cout << '\'' << ((char)i) << '\'' << " -- " << f[i] << endl;
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
					ss << '<' << i << "> - \n";
				else
					ss << '\'' << ((char)i) << "\' - \n";
				r[j].setFirst(ss.str());
				r[j].setSecond(freqs[i]);
				j++;
		}
		return r;
	}


