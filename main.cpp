#include <iostream>
#include <string>
using namespace std;
int main()
{
    char circle[80];
    for (int i = 0; i < 80; i++) {
        circle[i] = ' ';
    }
    string cir;
    cin.getline(circle, 80);
    cir.assign(circle);
    int left_bracket = cir.find('(');
    int right_bracket = cir.find(')');
    int first_space = cir.find(' ');
    bool Condition_is_met = true;
    if (left_bracket == -1 || right_bracket == -1) {
        cout << "Error at column 0: parenthesis expected" << endl;
        Condition_is_met = false;
    }
    int CircleTrue = cir.compare(0, first_space, "circle") * cir.compare(0, left_bracket, "circle")
        		   * cir.compare(0, first_space, "CIRCLE") * cir.compare(0, left_bracket, "CIRCLE");
    if (CircleTrue != 0) {
        cout << "Error at column 1: circle expected" << endl;
        Condition_is_met = false;
    }
    int comma = cir.find(',');
    if (comma == -1) {
        cout << "Error at column 2: wrong data" << endl;
        Condition_is_met = false;
    }
    bool is_a_number = false;
    int left_part = 0;
    int right_part = 0;
    for (int i = left_bracket + 1; i <= comma; i++) {
        if (cir[i] == ' ' || cir[i] == ',') {
            left_part++;
            is_a_number = false;
        }
        if ((cir[i] >= '0' && cir[i] <= '9') || cir[i] == '-' || cir[i] == ',') is_a_number = true; 
		else if (cir[i] == ' ') continue;
        else {
            cout << "Error at column 3: wrong symbols" << endl;
            Condition_is_met = false;
            break;
        }
    }
    is_a_number = false;
    for (int i = comma + 1; i <= right_bracket; i++) {
        if (cir[i] == ' ' || cir[i] == ')') {
            right_part++;
            is_a_number = false;
        }
        if ((cir[i] >= '0' && cir[i] <= '9') || cir[i] == '.' || cir[i] == ')') is_a_number = true;
        else if (cir[i] == ' ') continue;
        else {
            cout << "Error at column 3: wrong symbols" << endl;	
            Condition_is_met = false;
            break;
        }
    }
    if ((left_part == 1 || left_part == 0) || right_part == 0) {
        cout << "Error at column 4: wrong amount of data" << endl;
        Condition_is_met = false;
    }
    for (int i = right_bracket + 2; i < 80; i++) {
        if (circle[i] != ' ') {
            cout << "Error at column 5: unexpected token" << endl;
            Condition_is_met = false;
            break;
        }
    }
    if (Condition_is_met) {
        cout << cir;
    }
}

