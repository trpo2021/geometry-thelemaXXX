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
        int left_bracket, right_bracket;
        string entered_data;
        char numbering[80] = "circle0 0, 1";
        entered_data.assign(numbering);
        left_bracket = entered_data.find('(');
        right_bracket = entered_data.find(')');

        strcpy(numbering, "circle0 0, 1)");
        CHECK(zero_fault(left_bracket, right_bracket) != 1);
    }
}
