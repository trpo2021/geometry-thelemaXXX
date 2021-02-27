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
        cout << "Error at column 0: parenthesis expected" << endl;
        Condition_is_met = false;
    }
    int CircleTrue = txt.compare(0, first_space, "circle") * txt.compare(0, left_bracket, "circle")
                     * txt.compare(0, first_space, "CIRCLE")
                     * txt.compare(0, left_bracket, "CIRCLE");
    if (CircleTrue != 0) {
        cout << "Error at column 1: circle expected or first space before circle" << endl;
        Condition_is_met = false;
    }
    int circle = txt.find('e');
    if (circle + 1 == first_space) {
        cout << "Error at column 2: space after circle" << endl;
        Condition_is_met = false;
    }
    int comma = txt.find(',');
    if (comma == -1) {
        cout << "Error at column 3: wrong data" << endl;
        Condition_is_met = false;
    }
    int left_part = 0;
    int right_part = 0;
    for (int i = left_bracket + 1; i <= comma; i++) {
        if (txt[i] == ' ' || txt[i] == ',') {
            left_part++;
        }
        if ((txt[i] >= '0' && txt[i] <= '9') || txt[i] == '-' || txt[i] == ',')
            left_part += 0;
        else if (txt[i] == ' ')
            continue;
        else {
            cout << "Error at column 4: wrong symbols" << endl;
            Condition_is_met = false;
            break;
        }
    }
    if (Condition_is_met != false) {
        for (int i = comma + 1; i <= right_bracket; i++) {
            if (txt[i] == ' ' || txt[i] == ')') {
                right_part++;
            }
            if ((txt[i] >= '0' && txt[i] <= '9') || txt[i] == '.' || txt[i] == ')')
                right_part += 0;
            else if (txt[i] == ' ')
                continue;
            else {
                cout << "Error at column 4: wrong symbols" << endl;
                Condition_is_met = false;
                break;
            }
        }
    }
    if ((left_part == 1 || left_part == 0) || right_part == 0) {
        cout << "Error at column 5: wrong amount of data" << endl;
        Condition_is_met = false;
    }
    for (int i = right_bracket + 2; i < 80; i++) {
        if (text[i] != ' ') {
            cout << "Error at column 6: unexpected token" << endl;
            Condition_is_met = false;
            break;
        }
    }
    if (Condition_is_met) {
        cout << txt;
    }
}

