#include <iostream>
#include <cstdlib> // used for atof()
using namespace std;

string getUserInput(string prompt);
bool isFloatString(string s);
bool userContinue(string prompt);
bool parseArgs(int argc, char *argv[]);
void parseUser(string s);
void parseString(string s);

int main(int argc, char *argv[])
{
    if ( parseArgs(argc-1, argv) )
        parseUser( getUserInput("\nEnter a string: ") );

    return 0;
}

bool parseArgs(int argc, char *argv[])
{
    if (argc == 0)      // Do not run loop if only 1 arg.
        return true;

    parseString(argv[argc]);

    if (argc > 1)
        return parseArgs(argc-1, argv);
    else                                        // On last occurance, take user input,
        return userContinue("Continue? (Y/N)"); // and use it as the overall output.
}

void parseUser(string s)
{
    parseString(s);

    if (userContinue("Continue? (Y/N)"))
        parseUser(getUserInput("\nEnter a string: "));

    return;
}

void parseString(string s)
{
    if (isFloatString(s))
        cout << '"' << s << "\" is a float string with value: " << atof(s.c_str()) << endl;
    else
        cout << '"' << s << "\" is NOT a float string." << endl;
    return;
}

bool userContinue(string prompt)
{
    string cont = "";
    cout << '\n' << prompt << ' ';
    getline(cin, cont);
    if (cont[0] == 'y' || cont[0] == 'Y')
        return true;
    else if (cont[0] == 'n' || cont[0] == 'N')
        return false;
    else
        return userContinue("Error: Input not recognized!\nPress 'Y' or 'N' and press enter:");
}

string getUserInput(string prompt)
{
    string t = "";
    cout << prompt;
    getline(cin,t);
    return t;
}

bool isFloatString(string s)
{
    // determines if string is valid input for atof()
    int state = 1;
    for(unsigned int i = 0; i < s.length(); ++i) {
        switch (state) {
            // beginning state:
            case 1: if (s[i] == '+' || s[i] == '-')
                        state = 2;
                    else if (isdigit(s[i]))
                        state = 3;
                    else if (s[i] == '.')
                        state = 4;
                    else
                        return false;
                    break;
            // recieved sign:
            case 2: if (isdigit(s[i]))
                        state = 3;
                    else if (s[i] == '.')
                        state = 4;
                    else
                        return false;
                    break;
            // recieved >= one digit of coefficient:
            case 3: if (isdigit(s[i]))
                        state = 3;
                    else if (s[i] == '.')
                        state = 4;
                    else if (s[i] == 'e' || s[i] == 'E')
                        state = 6;
                    else
                        return false;
                    break;
            // recieved a decimal:
            case 4: if (isdigit(s[i]))
                        state = 5;
                    else
                        return false;
                    break;
            // recieved post decimal digits:
            case 5: if (isdigit(s[i]))
                        state = 5;
                    else if (s[i] == 'e' || s[i] == 'E')
                        state = 6;
                    else
                        return false;
                    break;
            // recieved E or e after valid coefficient:
            case 6: if (s[i] == '+' || s[i] == '-')
                        state = 7;
                    else if (isdigit(s[i]))
                        state = 8;
                    else
                        return false;
                    break;
            // recieved sign for exponent:
            case 7: if (isdigit(s[i]))
                        state = 8;
                    else
                        return false;
                    break;
            // recieved >= one digit of exponent:
            case 8: if (isdigit(s[i]))
                        break;
                    else
                        return false;
        }
    }
    if (state == 5 || state == 8)
        return true;
    else
        return false;
}
