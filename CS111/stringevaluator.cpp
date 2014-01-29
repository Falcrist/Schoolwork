#include <iostream>
#include <cstdlib> // used for atof()
using namespace std;

string getUserInput(string prompt = "\nEnter a string: ");
bool isFloatString(string s);
bool isHexString(string s);
bool isDateString(string s);
bool userContinue(string prompt = "Continue? (Y/N)");
bool parseArgs(int argc, char *argv[]);
void parseUser(string s);
void parseString(string s);
int atoh(string s);

int main(int argc, char *argv[])
{
    if ( parseArgs(argc-1, argv) )
        parseUser( getUserInput() );

    return 0;
}

bool parseArgs(int argc, char *argv[])
{
    if (argc == 0)      // Do not run loop if only 1 arg.
        return true;

    parseString(argv[argc]);

    if (argc > 1)
        return parseArgs(argc-1, argv);
    else                       // On last occurance, take user input,
        return userContinue(); // and use it as the overall output.
}

void parseUser(string s)
{
    parseString(s);

    if (userContinue())
        parseUser(getUserInput());

    return;
}

void parseString(string s)
{
    if (isFloatString(s))
        cout << '"' << s << "\" is a float string with value: " << atof(s.c_str()) << endl;
    else if (isHexString(s))
        cout << '"' << s << "\" is a HEX string with value: " << atoh(s) << endl;
    else if (isDateString(s))
        cout << '"' << s << "\" is a date string." << endl;
    else
        cout << '"' << s << "\" is NOT a float, hex, or date string." << endl;
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

bool isHexString(string s)
{
    int state = 0;
    for (unsigned int i =0; i < s.length(); ++i) {
        switch (state) {
            case 0: if (s[i] == '0')
                        state = 1;
                    else
                        return false;
                    break;
            case 1: if (s[i] == 'x' || s[i] == 'X')
                        state = 2;
                    else
                        return false;
                    break;
            case 2: if (isxdigit(s[i]))
                        state = 3;
                    else
                        return false;
                    break;
            case 3: if (isxdigit(s[i]))
                        break;
                    else
                        return false;
        }
    }
    if (state == 3)
        return true;
    else
        return false;
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

bool isDateString(string s)
{
    int state = 0;
    for(unsigned int i = 0; i < s.length(); ++i) {
        switch (state) {
            case 0: if (isdigit(s[i]))
                        state = 1;
                    else
                        return false;
                    break;
            case 1: if (isdigit(s[i]))
                        state = 2;
                    else
                        return false;
                    break;
            case 2: if (isdigit(s[i]))
                        state = 3;
                    else
                        return false;
                    break;
            case 3: if (isdigit(s[i]))
                        state = 4;
                    else
                        return false;
                    break;
            case 4: if (isdigit(s[i]))
                        state = 5;
                    else if (s[i] == 'W')
                        state = 9;
                    else if (s[i] == '-')
                        state = 12;
                    else
                        return false;
                    break;
            case 5: if (isdigit(s[i]))
                        state = 6;
                    else
                        return false;
                    break;
            case 6: if (isdigit(s[i]))
                        state = 7;
                    else
                        return false;
                    break;
            case 7: if (isdigit(s[i]))
                        state = 8;
                    else
                        return false;
                    break;
            case 8: return false;
            case 9: if (isdigit(s[i]))
                        state = 10;
                    else
                        return false;
                    break;
            case 10: if (isdigit(s[i]))
                        state = 11;
                    else
                        return false;
                    break;
            case 11: return false;
            case 12: if (isdigit(s[i]))
                        state = 13;
                    else
                        return false;
                    break;
            case 13: if (isdigit(s[i]))
                        state = 14;
                    else
                        return false;
                    break;
            case 14: if (s[i] == '-')
                        state = 15;
                    else
                        return false;
                    break;
            case 15: if (isdigit(s[i]))
                        state = 16;
                    else
                        return false;
                    break;
            case 16: if (isdigit(s[i]))
                        state = 17;
                    else
                        return false;
                    break;
            case 17: return false;
            case 18: if (isdigit(s[i]))
                        state = 19;
                    else
                        return false;
                    break;
            case 19: if (isdigit(s[i]))
                        state = 20;
                    else
                        return false;
                    break;
            case 20: if (s[i] == '-')
                        state = 21;
                    else
                        return false;
                    break;
            case 21: if (isdigit(s[i]))
                        state = 22;
                    else
                        return false;
                    break;
            case 22: return false;
        }
    }
    if (state == 2  || state == 4  || state == 6  || state == 7 ||
        state == 8  || state == 11 || state == 14 ||
        state == 17 || state == 20 || state == 22)
        return true;
    else
        return false;
}

int atoh(string s)
{
    unsigned int multi = 1;
    int total = 0;
    for (unsigned int i = s.length(); --i > 1; multi<<=4) {
        if (isdigit(s[i]))
            total += multi * (s[i] - '0');
        else if (s[i] >= 'a' && s[i] <= 'f')
            total += multi * (s[i] - 'a' + 10);
        else if (s[i] >= 'A' && s[i] <= 'F')
            total += multi * (s[i] - 'A' + 10);
    }
    return total;
}


/* Ugly POS recursive version:

int atoh(string s, int i)
{
    if (--i > 1) {
        if (isdigit(s[i]))
            return (1<<((s.length()-(i+1))*4)) * (s[i] - '0') + atoh(s,i);
        else if (s[i] >= 'a' && s[i] <= 'f')
            return (1<<((s.length()-(i+1))*4)) * (s[i] - 'a' + 10) + atoh(s,i);
        else if (s[i] >= 'A' && s[i] <= 'F')
            return (1<<((s.length()-(i+1))*4)) * (s[i] - 'A' + 10) + atoh(s,i);
    }
    return 0;

} */
