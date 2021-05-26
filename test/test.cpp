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
    SECTION("Errors")
    {
        int left_bracket, right_bracket, comma;
        string entered_data;
        *char numbering[80] = "circle0 0, 1";
        entered_data.assign(numbering);
        left_bracket = entered_data.find('(');
        right_bracket = entered_data.find(')');
        strcpy(numbering, "circle0 0, 1)");
        CHECK(zero_fault(left_bracket, right_bracket) != 1);
 
        *numbering[80] = "circl(0 0, 1)";
        entered_data.assign(numbering);
        left_bracket = entered_data.find('(');
        right_bracket = entered_data.find(')');
        strcpy(numbering, "circl(0 0, 1)");
        CHECK(first_fault(left_bracket, right_bracket) != 1);

        *numbering[80] = "circle(0 0 1)";
        entered_data.assign(numbering);
        comma = entered_data.find(',');
        strcpy(numbering, "circle(0 0 1)");
        CHECK(second_fault(comma) != 1);
        
        *numbering[80] = "circle(1.1 0, 1)";
        entered_data.assign(numbering);
        comma = entered_data.find(',');
        left_bracket = entered_data.find('(');
        right_bracket = entered_data.find(')');
        strcpy(numbering, "circle(1.1 0, 1)");
        CHECK(third_fault(left_bracket, comma, entered_data) != 1);
        
        *numbering[80] = "circle(0 +0, 1)";
        entered_data.assign(numbering);
        comma = entered_data.find(',');
        left_bracket = entered_data.find('(');
        strcpy(numbering, "circle(0 +0, 1)");
        CHECK(fourth_fault(left_bracket, comma, entered_data) != 1);
        
        *numbering[80] = "circle(0, 1)";
        entered_data.assign(numbering);
        comma = entered_data.find(',');
        left_bracket = entered_data.find('(');
        strcpy(numbering, "circle(0, 1)");
        CHECK(fifth_fault(left_bracket, comma, entered_data) != 1);
        
        *numbering[80] = "circle(0 0, )";
        entered_data.assign(numbering);
        comma = entered_data.find(',');
        right_bracket = entered_data.find(')');
        strcpy(numbering, "circle(0 0, )");
        CHECK(sixth_fault(comma, right_bracket, entered_data) != 1);
        
        *numbering[80] = "circle(0 0, -1)";
        entered_data.assign(numbering);
        comma = entered_data.find(',');
        right_bracket = entered_data.find(')');
        strcpy(numbering, "circle(0 0, -1)");
        CHECK(seventh_fault(comma, right_bracket, entered_data) != 1);
        
        *numbering[80] = "circle(0 0, +1)";
        entered_data.assign(numbering);
        comma = entered_data.find(',');
        right_bracket = entered_data.find(')');
        strcpy(numbering, "circle(0 0, +1)");
        CHECK(eighth_fault(comma, right_bracket, entered_data) != 1);
        
        *numbering[80] = "circle(0 0,, 1)";
        entered_data.assign(numbering);
        left_bracket = entered_data.find('(');
        right_bracket = entered_data.find(')');
        strcpy(numbering, "circle(0 0,, 1)");
        CHECK(ninth_fault(left_bracket, right_bracket, entered_data) != 1);
        
        *numbering[80] = "circle(0 0, 1)4214";
        entered_data.assign(numbering);
        right_bracket = entered_data.find(')');
        strcpy(numbering, "circle(0 0, 1)4214");
        CHECK(tenth_fault(right_bracket, numbering) != 1);
    }
}
