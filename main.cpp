#include <iostream>
#include <string>
using namespace std;
int main()
{
    char text[80];
    for (int i = 0; i < 80; i++) {
        text[i] = ' ';
    }
    string txt;
    cin.getline(text, 80);
    txt.assign(text);
    int left_bracket = txt.find('(');
    int right_bracket = txt.find(')');
    int first_space = txt.find(' ');
    bool Condition_is_met = true;
    if (left_bracket == -1 || right_bracket == -1) {
        cout << "Error at column 0: parenthesis not entered" << endl;
        Condition_is_met = false;
    }
    int CircleTrue = txt.compare(0, first_space, "circle") * txt.compare(0, left_bracket, "circle")
                     * txt.compare(0, first_space, "CIRCLE")
                     * txt.compare(0, left_bracket, "CIRCLE");
    int c = txt.find('c');
    while (1) {
        if (c - 1 == first_space) {
            cout << "Error at column 1: space before circle" << endl;
            Condition_is_met = false;
            break;
        } else if (CircleTrue != 0) {
            cout << "Error at column 2: circle not entered" << endl;
            Condition_is_met = false;	
            break;
        } else
            break;
    }
    int comma = txt.find(',');
    if (comma == -1) {
        cout << "Error at column 3: comma not entered" << endl;
        Condition_is_met = false;
    }
    for (int i = left_bracket + 1; i <= comma; i++) {
        if ((txt[i] >= '0' && txt[i] <= '9') || txt[i] == '-' || txt[i] == ' ' || txt[i] == ',')
            continue;
        else if (txt[i] == '.') {
            cout << "Error at column 4: coordinates must be integers" << endl;
            Condition_is_met = false;
            break;
        } else {
            cout << "Error at column 5: incorrect symbols before comma" << endl;
            Condition_is_met = false;
            break;
        }
    }
    if (Condition_is_met != false) {
        for (int i = comma + 1; i <= right_bracket; i++) {
            if ((txt[i] >= '0' && txt[i] <= '9') || txt[i] == '.' || txt[i] == ',' || txt[i] == ' '
                || txt[i] == ')')
                continue;
            else if (txt[i] == '-') {
                cout << "Error at column 6: radius cannot be negative" << endl;
                Condition_is_met = false;
                break;
            } else {
                cout << "Error at column 7: incorrect symbols after comma" << endl;
                Condition_is_met = false;
                break;
            }
        }
    }
    int j = 0;
    for (int k = left_bracket; k <= right_bracket + 10; k++) {
        if (txt[k] == ',' || txt[k] == ')' || txt[k] == '(')
            j++;
        if ((txt[k] >= '0' && txt[k] <= '9') || txt[k] == '-' || txt[k] == ',' || txt[k] == ' ')
            continue;
        else if (j > 3) {
            cout << "Error at column 8: wrong amount of data" << endl;
            Condition_is_met = false;
            break;
        }
    }
    for (int i = right_bracket + 2; i < 80; i++) {
        if (text[i] != ' ') {
            cout << "Error at column 9: extra characters" << endl;
            Condition_is_met = false;
            break;
        }
    }
    if (Condition_is_met) {
        cout << txt;
    }
}

