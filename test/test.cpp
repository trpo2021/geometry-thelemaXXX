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
        int left_bracket, right_bracket, first_space, comma, CircleTrue;
        string entered_data;
        char numbering[80] = "circle0 0, 1";
        entered_data.assign(numbering);
        left_bracket = entered_data.find('(');
        right_bracket = entered_data.find(')');
        first_space = entered_data.find(' ');
        CircleTrue = entered_data.compare(0, first_space, "circle")
            * entered_data.compare(0, left_bracket, "circle")
            * entered_data.compare(0, first_space, "CIRCLE")
            * entered_data.compare(0, left_bracket, "CIRCLE");

        comma = entered_data.find(',');

        strcpy(numbering, "circle0 0, 1)");
        CHECK(zero_fault(left_bracket, right_bracket) != 1);
    }
}
