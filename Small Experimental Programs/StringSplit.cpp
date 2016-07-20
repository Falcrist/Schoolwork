#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Splits incomming string into vector of tokens based on a delimiter.
vector<string> tmpVec(string &s, char delim, bool PurgeEmpty)
{
	vector<string> tmp;
	stringstream ss(s);
	while (getline(ss, s, delim))
		if (!PurgeEmpty || s.length() > 0)
			tmp.push_back(s);
	return tmp;
}

// Splits an incomming string into a vector of tokens based on the delimiters provided.
// Empty tokens are omitted by default.
vector<string> StringSplit(const string &s, vector<char> delims = {' ', '\t', '\n'}, bool PurgeEmpty = true)
{
	vector<string> tmp, toks = { s };
	for (auto delim : delims)
		for (auto i = toks.begin(); i < toks.end(); ++i)
			if ((*i).find(delim) != (*i).npos) {
        tmp = tmpVec(*i, delim, PurgeEmpty);
				i = toks.insert(toks.erase(i), tmp.begin(), tmp.end()) + tmp.size() - 1;
			}
	return toks;
}

// Main function is just for demonstration.
int main()
{
	string inStr;
	cout << "Enter names:\n";
	getline(cin, inStr);
	vector<string> tokens = StringSplit(inStr);
	for (auto tok: tokens)
		cout << "Hello, " << tok << "!\n";
    return 0;
}
