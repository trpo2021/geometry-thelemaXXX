#include "libgeometry/crossing.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

double radius(int comma, int right_bracket, string entered_data)
{
    int count = 0;
    double print = 0;
    char radius[10];

    for (int i = comma + 1; i < right_bracket; i++) {
        if (entered_data[i] == '-' || entered_data[i] == ' ')
            continue;
        else if (
            (entered_data[i] >= '0' && entered_data[i] <= '9')
            || entered_data[i] == '.') {
            radius[count] = entered_data[i];
            count++;
        }
        else {
            break;
        }
    }
    return print = atof(radius);
}

double first(int left_bracket, int comma, string entered_data)
{
    int count = 0;
    double print = 0;
    char x[10];

    for (int i = left_bracket + 1; i < comma; i++) {

        if (entered_data[i] == ' ')
            continue;

        else if (entered_data[i] == '-' || (entered_data[i] >= '0' && entered_data[i] <= '9') || entered_data[i] == '.') {

            x[count] = entered_data[i];
            count++;

            if (!(entered_data[i + 1] >= '0' && entered_data[i + 1] <= '9') || entered_data[i + 1] != '.')
                break;
            else
                continue;
        }
        else
            break;
    }
    return print = atof(x);
}

double second(int left_bracket, int comma, string entered_data)
{
    int count = 0;
    double print = 0;
    char x[10];

    for (int i = left_bracket + 1; i < comma; i++) {

        if (entered_data[i] == ' ')
            continue;

        else if (entered_data[i] == '-' || (entered_data[i] >= '0' && entered_data[i] <= '9') || entered_data[i] == '.') {

            if (!(entered_data[i + 1] >= '0' && entered_data[i + 1] <= '9') || entered_data[i + 1] != '.') {

                if (entered_data[i + 1] == '-' || entered_data[i + 1] == ' ') {

                    for (i = i + 1; i < comma; i++) {

                        if (entered_data[i] == ' ')
                            continue;
                        else if (entered_data[i] == '-' || (entered_data[i] >= '0' && entered_data[i] <= '9') || entered_data[i] == '.') {
                            x[count] = entered_data[i];
                            count++;
                        }
                        else if (!(entered_data[i + 1] >= '0' && entered_data[i + 1] <= '9') || entered_data[i + 1] != '.')
                            return atof(x);

                        else
                            continue;
                    }
                }
            }
            else
                continue;
        }

        else
            continue;
    }
    return print = atof(x);
}
