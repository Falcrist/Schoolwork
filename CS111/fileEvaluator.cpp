/* Talen Phillips
 * CS111-01
 * 31JAN2013
 * "File Evaluator"
 *
 * This program prompts the user to open a file, then evaluates each string
 * within that file to determine if it is a valid floating point number,
 * hexidecimal number, or date format.
 */

#include <iostream>
#include <fstream>
#include <cstdlib> // used for atof() and strtol()
using namespace std;

// using prototyping and default arguments
string getUserInput(string prompt = "Enter a file name (with path): ");
bool isFloatString(string s);
bool isHexString(string s);
bool isDateString(string s);
bool userContinue(string prompt = "Continue? (Y/N)");
bool parseArgs(int argc, char *argv[]);
void parseUser(string s);
void parseFile(string s);
void parseString(string s);

int main(int argc, char *argv[])
{
    if ( parseArgs(argc-1, argv) ) // returns userContinue() if it runs
        parseUser( getUserInput() );
    return 0;
}

bool parseArgs(int argc, char *argv[])
// evaluates each additional argument starting with the final one
{
    if (argc == 0)              // Do not run loop if only 1 arg.
        return true;
    parseFile(argv[argc]);
    if (argc > 1)
        return parseArgs(argc-1, argv);
    else                        // On last occurance, take user input,
        return userContinue();  // and use it as the overall output.
}

void parseUser(string s)
// recursive control loop
{
    parseFile(s);
    if (userContinue())
        parseUser( getUserInput() );
    return;
}

void parseFile(string s)
// opens file who's name is passed in through argument, and evaluates each string
{
    ifstream myfile;
    myfile.open( s.c_str() );
    if ( myfile.is_open() ) {
        while (myfile >> s)
            parseString(s);
        myfile.close();
        cout << endl;
    }
    else
        cout << "Error! File not found.\nCheck file name and path, and try again." << endl;
    return;
}

void parseString(string s)
// checks each string to see if it's a float, hex, or date
{
    if (isFloatString(s))
        cout << '"' << s << "\" is a float string with value: " << atof(s.c_str()) << endl;
    else if (isHexString(s))
        cout << '"' << s << "\" is a HEX string with value: " << strtol(s.c_str(), '\0', 0) << endl;
    else if (isDateString(s))
        cout << '"' << s << "\" is a date string." << endl;
    return;
}

bool userContinue(string prompt)
// prompts user to continue or not. recurs on invalid input.
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
// prompts user to enter a string
{
    string t = "";
    cout << prompt;
    getline(cin,t);
    return t;
}

bool isHexString(string s)
// Determines if a string is a properly formatted hex number: 0x###...
{
    int state = 0;
    for (unsigned int i =0; i < s.length(); ++i) {
        switch (state) {
            case 0: if (s[i] == '0')                //begin
                        state = 1;
                    else
                        return false;
                    break;
            case 1: if (s[i] == 'x' || s[i] == 'X') //received '0'
                        state = 2;
                    else
                        return false;
                    break;
            case 2: if (isxdigit(s[i]))             //received x
                        state = 3;
                    else
                        return false;
                    break;
            case 3: if (isxdigit(s[i]))             //received >= one digit
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
// determines if string is valid input for atof()
{
    int state = 0;
    for(unsigned int i = 0; i < s.length(); ++i) {
        switch (state) {
            case 0: if (s[i] == '+' || s[i] == '-')
                        state = 1;
                    else if (isdigit(s[i]))
                        state = 2;
                    else if (s[i] == '.')
                        state = 3;
                    else
                        return false;
                    break;
            // recieved sign:
            case 1: if (isdigit(s[i]))
                        state = 2;
                    else if (s[i] == '.')
                        state = 3;
                    else
                        return false;
                    break;
            // recieved >= one digit of coefficient:
            case 2: if (isdigit(s[i]))
                        state = 2;
                    else if (s[i] == '.')
                        state = 3;
                    else if (s[i] == 'e' || s[i] == 'E')
                        state = 5;
                    else
                        return false;
                    break;
            // recieved a decimal:
            case 3: if (isdigit(s[i]))
                        state = 4;
                    else
                        return false;
                    break;
            // recieved post decimal digits:
            case 4: if (isdigit(s[i]))
                        state = 4;
                    else if (s[i] == 'e' || s[i] == 'E')
                        state = 5;
                    else
                        return false;
                    break;
            // recieved E or e after valid coefficient:
            case 5: if (s[i] == '+' || s[i] == '-')
                        state = 6;
                    else if (isdigit(s[i]))
                        state = 7;
                    else
                        return false;
                    break;
            // recieved sign for exponent:
            case 6: if (isdigit(s[i]))
                        state = 7;
                    else
                        return false;
                    break;
            // recieved >= one digit of exponent:
            case 7: if (isdigit(s[i]))
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
// Determines if a string is a properly formatted date.
{
    int state = 0;
    for(unsigned int i = 0; i < s.length(); ++i) {
        switch (state) {
            case 0: if (isdigit(s[i]))      //begin
                        state = 1;
                    else
                        return false;
                    break;
            case 1: if (isdigit(s[i]))      //received Y
                        state = 2;
                    else
                        return false;
                    break;
            case 2: if (isdigit(s[i]))      //received YY
                        state = 3;
                    else
                        return false;
                    break;
            case 3: if (isdigit(s[i]))      //received YYY
                        state = 4;
                    else
                        return false;
                    break;
            case 4: if (isdigit(s[i]))      //received YYYY
                        state = 5;
                    else if (s[i] == 'W')
                        state = 9;
                    else if (s[i] == '-')
                        state = 13;
                    else
                        return false;
                    break;
            case 5: if (isdigit(s[i]))      //received YYYY#
                        state = 6;
                    else
                        return false;
                    break;
            case 6: if (isdigit(s[i]))      //received YYYY##
                        state = 7;
                    else
                        return false;
                    break;
            case 7: if (isdigit(s[i]))      //received YYYY###
                        state = 8;
                    else
                        return false;
                    break;
            case 8: return false;           //received YYYYMMDD
            case 9: if (isdigit(s[i]))      //received YYYYW
                        state = 10;
                    else
                        return false;
                    break;
            case 10: if (isdigit(s[i]))     //received YYYYWw
                        state = 11;
                    else
                        return false;
                    break;
            case 11: if (isdigit(s[i]))     //received YYYYWww
                        state = 12;
                    else
                        return false;
                    break;
            case 12: return false;          //received YYYYWwwd
            case 13: if (isdigit(s[i]))     //received YYYY-
                        state = 14;
                    else if (s[i] == 'W')
                        state = 20;
                    else
                        return false;
                    break;
            case 14: if (isdigit(s[i]))     //received YYYY-#
                        state = 15;
                    else
                        return false;
                    break;
            case 15: if (s[i] == '-')       //received YYYY-##
                        state = 16;
                    else if (isdigit(s[i]))
                        state = 19;
                    else
                        return false;
                    break;
            case 16: if (isdigit(s[i]))     //received YYYY-MM-
                        state = 17;
                    else
                        return false;
                    break;
            case 17: if (isdigit(s[i]))     //received YYYY-MM-D
                        state = 18;
                    else
                        return false;
                    break;
            case 18: return false;          //received YYYY-MM-DD
            case 19: return false;          //received YYYY-DDD
            case 20: if (isdigit(s[i]))     //received YYYY-W
                        state = 21;
                    else
                        return false;
                    break;
            case 21: if (isdigit(s[i]))     //received YYYY-Ww
                        state = 22;
                    else
                        return false;
                    break;
            case 22: if (s[i] == '-')       //received YYYY-Www
                        state = 23;
                    else
                        return false;
                    break;
            case 23: if (isdigit(s[i]))     //received YYYY-Www-
                        state = 24;
                    else
                        return false;
                    break;
            case 24: return false;          //received YYYY-Www-d
        }
    }
    if ( state == 2  || state == 4  || state == 6  || state == 7  ||
         state == 8  || state == 11 || state == 12 || state == 15 ||
         state == 18 || state == 19 || state == 22 || state == 24 )
        return true;
    else
        return false;
}
