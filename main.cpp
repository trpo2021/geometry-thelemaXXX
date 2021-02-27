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
    int left_par = cir.find('(');
    int right_par = cir.find(')', left_par);
    int first_space = cir.find(' ');
    bool IsDataTrue = true;
    if (left_par == -1 || right_par == -1) {
        cout << "Error at column 0: parenthesis expected" << endl;
        IsDataTrue = false;
    }
    int CircleTrue = cir.compare(0, first_space, "circle") * cir.compare(0, left_par, "circle")
                     * cir.compare(0, first_space, "CIRCLE") * cir.compare(0, left_par, "CIRCLE");
    if (CircleTrue != 0) {
        cout << "Error at column 1: circle expected" << endl;
        IsDataTrue = false;
    }
    int comma = cir.find(',', left_par);
    if (comma == -1) {
        cout << "Error at column 2: wrong data" << endl;
        IsDataTrue = false;
    }
    bool IsNumber = false;
    int lcount = 0;
    int rcount = 0;
    for (int i = left_par + 1; i <= comma; i++) {
        if ((cir[i] == ' ' || cir[i] == ',') && IsNumber) {
            lcount++;
            IsNumber = false;
        }
        if ((cir[i] >= '0' && cir[i] <= '9') || cir[i] == ',') {
            IsNumber = true;
        } else if (cir[i] == ' ')
            continue;
        else {
            cout << "Error at column 3: wrong symbols" << endl;
            IsDataTrue = false;
            break;
        }
    }
    IsNumber = false;
    for (int i = comma + 1; i <= right_par; i++) {
        if ((cir[i] == ' ' || cir[i] == ')') && IsNumber) {
            rcount++;
            IsNumber = false;
        }
        if ((cir[i] >= '0' && cir[i] <= '9' || cir[i] == '.') || cir[i] == ')')
            IsNumber = true;
        else if (cir[i] == ' ')
            continue;
        else {
            cout << "Error at column 3: wrong symbols" << endl;
            IsDataTrue = false;
            break;
        }
    }
    if (lcount != 2 || rcount != 1) {
        cout << "Error at column 4: wrong amount of data" << endl;
        IsDataTrue = false;
    }
    for (int i = right_par + 2; i < 80; i++) {
        if (circle[i] != ' ') {
            cout << "Error at column 5: unexpected token" << endl;
            IsDataTrue = false;
            break;
        }
    }
    if (IsDataTrue) {
        cout << cir;
    }
    return 0;
}
