#define CATCH_CONFIG_MAIN
#include "../thirdparty/catch.hpp"
#include "libgeometry/check.h"
#include "libgeometry/computation.h"
#include "libgeometry/crossing.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
using namespace std;

TEST_CASE("Circle")
{
    SECTION("Check")
    {
        int left_bracket, right_bracket, comma, CircleTrue, first_space;
        string entered_data;
        char numbering0[80] = "circle0 0, 1";
        entered_data.assign(numbering0);
        left_bracket = entered_data.find('(');
        right_bracket = entered_data.find(')');
        strcpy(numbering0, "circle0 0, 1)");
        CHECK(zero_fault(left_bracket, right_bracket) != 1);
 
        char numbering1[80] = "circl(0 0, 1)";
        entered_data.assign(numbering1);
        left_bracket = entered_data.find('(');
        right_bracket = entered_data.find(')');
        first_space = entered_data.find(' ');
        CircleTrue = entered_data.compare(0, first_space, "circle")
            * entered_data.compare(0, left_bracket, "circle")
            * entered_data.compare(0, first_space, "CIRCLE")
            * entered_data.compare(0, left_bracket, "CIRCLE");
        strcpy(numbering1, "circl(0 0, 1)");
        CHECK(first_fault(CircleTrue) != 1);

        char numbering2[80] = "circle(0 0 1)";
        entered_data.assign(numbering2);
        comma = entered_data.find(',');
        strcpy(numbering2, "circle(0 0 1)");
        CHECK(second_fault(comma) != 1);
        
        char numbering3[80] = "circle(1.1 0, 1)";
        entered_data.assign(numbering3);
        comma = entered_data.find(',');
        left_bracket = entered_data.find('(');
        right_bracket = entered_data.find(')');
        strcpy(numbering3, "circle(1.1 0, 1)");
        CHECK(third_fault(left_bracket, comma, entered_data) != 1);
        
        char numbering4[80] = "circle(0 +0, 1)";
        entered_data.assign(numbering4);
        comma = entered_data.find(',');
        left_bracket = entered_data.find('(');
        strcpy(numbering4, "circle(0 +0, 1)");
        CHECK(fourth_fault(left_bracket, comma, entered_data) != 1);
        
        char numbering5[80] = "circle(0, 1)";
        entered_data.assign(numbering5);
        comma = entered_data.find(',');
        left_bracket = entered_data.find('(');
        strcpy(numbering5, "circle(0, 1)");
        CHECK(fifth_fault(left_bracket, comma, entered_data) != 1);
        
        char numbering6[80] = "circle(0 0, )";
        entered_data.assign(numbering6);
        comma = entered_data.find(',');
        right_bracket = entered_data.find(')');
        strcpy(numbering6, "circle(0 0, )");
        CHECK(sixth_fault(comma, right_bracket, entered_data) != 1);
        
        char numbering7[80] = "circle(0 0, -1)";
        entered_data.assign(numbering7);
        comma = entered_data.find(',');
        right_bracket = entered_data.find(')');
        strcpy(numbering7, "circle(0 0, -1)");
        CHECK(seventh_fault(comma, right_bracket, entered_data) != 1);
        
        char numbering8[80] = "circle(0 0, +1)";
        entered_data.assign(numbering8);
        comma = entered_data.find(',');
        right_bracket = entered_data.find(')');
        strcpy(numbering8, "circle(0 0, +1)");
        CHECK(eighth_fault(comma, right_bracket, entered_data) != 1);
        
        char numbering9[80] = "circle(0 0,, 1)";
        entered_data.assign(numbering9);
        left_bracket = entered_data.find('(');
        right_bracket = entered_data.find(')');
        strcpy(numbering9, "circle(0 0,, 1)");
        CHECK(ninth_fault(left_bracket, right_bracket, entered_data) != 1);
        
        char numbering10[80] = "circle(0 0, 1)4214";
        entered_data.assign(numbering10);
        right_bracket = entered_data.find(')');
        strcpy(numbering10, "circle(0 0, 1)4214");
        CHECK(tenth_fault(right_bracket, numbering10) != 1);
    }
}

TEST_CASE("Crossing")
{
	SECTION("radius")
    {
        int right_bracket, comma, left_bracket;
        string entered_data;
        char numbering11[80] = "circle(0 0, 1)";
        entered_data.assign(numbering11);
        right_bracket = entered_data.find(')');
        comma = entered_data.find(',');
        strcpy(numbering11, "circle(0 0, 1)");
        CHECK(radius (comma, right_bracket, entered_data) == 1);
   
        char numbering12[80] = "circle(1 0, 0)";
        entered_data.assign(numbering12);
        left_bracket = entered_data.find('(');
        comma = entered_data.find(',');
        strcpy(numbering12, "circle(0 0, 1)");
        CHECK(first(left_bracket, comma, entered_data) == 1);
        
        char numbering13[80] = "circle(0 1, 0)";
        entered_data.assign(numbering13);
        left_bracket = entered_data.find('(');
        comma = entered_data.find(',');
        strcpy(numbering13, "circle(0 1, 0)");
        CHECK(second(left_bracket, comma, entered_data) == 1);
	}
}
