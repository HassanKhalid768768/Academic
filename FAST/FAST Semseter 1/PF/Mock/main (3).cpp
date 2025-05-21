#include <iostream>
using namespace std;
 
void morseEncode(char x)
{
 
    switch (x) {
    case 'A':
        return ".---.";
    case 'B':
        return "-...-";
    case 'C':
        return "-.--.";
    case 'D':
        return "---..";
    case 'E':
        return ".-.-.";
    case 'F':
        return "..--.";
    case 'G':
        return "----.";
    case 'H':
        return "....-";
    case 'I':
        return "..---";
    case 'J':
        return ".----";
    case 'K':
        return "--.--";
    case 'L':
        return ".--.";
    case 'M':
        return "---.-";
    case 'N':
        return "--...";
    case 'O':
        return "-----";
    case 'P':
        return "-.---";
    case 'Q':
        return "-..--";
    case 'R':
        return ".-...";
    case 'S':
        return "...--";
    case 'T':
        return "-....";
    case 'U':
        return "..-..";
    case 'V':
        return "...-.";
    case 'W':
        return "--.-.";
    case 'X':
        return "-..-.";
    case 'Y':
        return "-.-.-";
    case 'Z':
        return "--..-";
    case ' ':
        return ".....";
    default:
        cerr << "Found invalid character: " << x << ' '
             << std::endl;
        exit(0);
    }
}
 
void morseCode(string s)
{
 
    // character by character print
    // Morse code
    for (int i = 0; s[i]; i++)
        cout << morseEncode(s[i]);
    cout << endl;
}
 
// Driver's code
int main()
{
    string s = "THIS IS MESSAGE";
    morseCode(s);
    return 0;
}
