#include "libgeometry/check.h"
#include "libgeometry/computation.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main() {
    int left_bracket, right_bracket, first_space, comma, CircleTrue,
            Condition_is_met = 1;
    char numbering[80];
    string entered_data;

    for (int i = 0; i < 80; i++)
        numbering[i] = ' ';

    cin.getline(numbering, 80);
    entered_data.assign(numbering);
    left_bracket = entered_data.find('(');
    right_bracket = entered_data.find(')');
    first_space = entered_data.find(' ');
    CircleTrue = entered_data.compare(0, first_space, "circle")
            * entered_data.compare(0, left_bracket, "circle")
            * entered_data.compare(0, first_space, "CIRCLE")
            * entered_data.compare(0, left_bracket, "CIRCLE");

    comma = entered_data.find(',');

    if (zero_fault(left_bracket, right_bracket) != 1) {
        Condition_is_met = 0;
        cout << "Error at column 0: parenthesis not entered" << endl;
    }

    if (first_fault(CircleTrue) != 1) {
        Condition_is_met = 0;
        cout << "Error at column 1: circle not entered" << endl;
    }

    if (second_fault(comma) != 1) {
        Condition_is_met = 0;
        cout << "Error at column 2: comma not entered" << endl;
    }

    if (third_fault(left_bracket, comma, entered_data) != 1) {
        Condition_is_met = 0;
        cout << "Error at column 3: coordinates must be integers" << endl;
    }

    if (fourth_fault(left_bracket, comma, entered_data) != 1) {
        Condition_is_met = 0;
        cout << "Error at column 4: incorrect symbols before comma" << endl;
    }

    if (fifth_fault(left_bracket, comma, entered_data) != 1) {
        Condition_is_met = 0;
        cout << "Error at column 5: coordinates not entered" << endl;
    }

    if (sixth_fault(comma, right_bracket, entered_data) != 1) {
        Condition_is_met = 0;
        cout << "Error at column 6: radius not entered" << endl;
    }

    if (seventh_fault(comma, right_bracket, entered_data) != 1) {
        Condition_is_met = 0;
        cout << "Error at column 7: radius cannot be negative" << endl;
    }

    if (eighth_fault(comma, right_bracket, entered_data) != 1) {
        Condition_is_met = 0;
        cout << "Error at column 8: incorrect symbols after comma" << endl;
    }

    if (ninth_fault(left_bracket, right_bracket, entered_data) != 1) {
        Condition_is_met = 0;
        cout << "Error at column 9: wrong amount of data" << endl;
    }

    if (tenth_fault(right_bracket, numbering) != 1) {
        Condition_is_met = 0;
        cout << "Error at column 10: extra characters" << endl;
    }

    if (Condition_is_met == 1)
        cout << entered_data << endl;

    if (Condition_is_met == 1)
        cout << "perimeter = "
             << computation_perimeter(comma, right_bracket, entered_data)
             << endl
             << "area = "
             << computation_area(comma, right_bracket, entered_data) << endl;

    system("pause");
    return 0;
}
