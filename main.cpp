#include <iostream>
#include <string>
using namespace std;
int main()
{
    char numbering[80];
    for (int i = 0; i < 80; i++) {
        numbering[i] = ' ';
    }
    string entered_data;
    cin.getline(numbering, 80);
    entered_data.assign(numbering);
    int left_bracket = entered_data.find('(');
    int right_bracket = entered_data.find(')');
    int first_space = entered_data.find(' ');
    bool Condition_is_met = true;
    if (left_bracket == -1 || right_bracket == -1) {
        cout << "Error at column 0: parenthesis not entered" << endl;
        Condition_is_met = false;
    }
    int CircleTrue = entered_data.compare(0, first_space, "circle") * entered_data.compare(0, left_bracket, "circle")
                     * entered_data.compare(0, first_space, "CIRCLE")
                     * entered_data.compare(0, left_bracket, "CIRCLE");
    if (CircleTrue != 0) {
            cout << "Error at column 1: circle not entered" << endl;
            Condition_is_met = false;
        }
    int comma = entered_data.find(',');
    if (comma == -1) {
        cout << "Error at column 2: comma not entered" << endl;
        Condition_is_met = false;
    }
    for (int i = left_bracket + 1; i <= comma; i++) {
        if ((entered_data[i] >= '0' && entered_data[i] <= '9') || entered_data[i] == '-' || entered_data[i] == ' ' || entered_data[i] == ',')
            continue;
        else if (entered_data[i] == '.') {
            cout << "Error at column 3: coordinates must be integers" << endl;
            Condition_is_met = false;
            break;
        } else {
            cout << "Error at column 4: incorrect symbols before comma" << endl;
            Condition_is_met = false;
            break;
        }
    }
    for (int i = left_bracket + 1; i <= comma; i++) {
        if (entered_data[i] == '-' || entered_data[i] == ' ' || entered_data[i] == '.')
            continue;
        else if (entered_data[i] >= '0' && entered_data[i] <= '9') {
            break;
        } else {
            cout << "Error at column 5: coordinates not entered" << endl;
            Condition_is_met = false;
        }
    }
    if (Condition_is_met != false) {
        for (int i = comma + 1; i <= right_bracket; i++) {
            if ((entered_data[i] >= '0' && entered_data[i] <= '9') || entered_data[i] == '.' || entered_data[i] == ',' || entered_data[i] == ' '
                || entered_data[i] == ')')
                continue;
            else if (entered_data[i] == '-') {
                cout << "Error at column 7: radius cannot be negative" << endl;
                Condition_is_met = false;
                break;
            } else {
                cout << "Error at column 8: incorrect symbols after comma" << endl;
                Condition_is_met = false;
                break;
            }
        }
    }
    for (int i = comma + 1; i <= right_bracket; i++) {
        if (entered_data[i] == '-' || entered_data[i] == ' ' || entered_data[i] == '.')
            continue;
        else if (entered_data[i] >= '0' && entered_data[i] <= '9') {
            break;
        } else {
            cout << "Error at column 6: radius not entered" << endl;
            Condition_is_met = false;
            break;
        }
    }
    int j = 0;
    for (int k = left_bracket; k <= right_bracket + 10; k++) {
        if (entered_data[k] == ',' || entered_data[k] == ')' || entered_data[k] == '(')
            j++;
        if ((entered_data[k] >= '0' && entered_data[k] <= '9') || entered_data[k] == '-' || entered_data[k] == ',' || entered_data[k] == ' ')
            continue;
        else if (j > 3) {
            cout << "Error at column 9: wrong amount of data" << endl;
            Condition_is_met = false;
            break;
        }
    }
    if (right_bracket != -1){
    for (int i = right_bracket + 2; i < 80; i++) {
        if (numbering[i] != ' ') {
            cout << "Error at column 10: extra characters" << endl;
            Condition_is_met = false;
            break;
        }
    }
}
    if (Condition_is_met) {
        cout << entered_data;
    }
}

