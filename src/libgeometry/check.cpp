#include "libgeometry/check.h"
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

int zero_fault(int left_bracket, int right_bracket)
{
    if (left_bracket == -1 || right_bracket == -1)
        return 0;
    else
        return 1;
}

int first_fault(int CircleTrue)
{
    if (CircleTrue != 0)
        return 0;
    else
        return 1;
}

int second_fault(int comma)
{
    if (comma == -1)
        return 0;
    else
        return 1;
}

int third_fault(int left_bracket, int comma, string entered_data)
{
    for (int i = left_bracket + 1; i < comma; i++) {
        if (entered_data[i] == '.')
            return 0;
    }
    return 1;
}

int fourth_fault(int left_bracket, int comma, string entered_data)
{
    for (int i = left_bracket + 1; i < comma; i++) {
        if ((entered_data[i] >= '0' && entered_data[i] <= '9') || entered_data[i] == '-' || entered_data[i] == ' ')
            continue;
        else
            return 0;
    }
    return 1;
}

int fifth_fault(int left_bracket, int comma, string entered_data)
{
    int count = 0;

    for (int i = left_bracket + 1; i < comma; i++) {
        if (entered_data[i] >= '0' && entered_data[i] <= '9') {
            if (entered_data[i + 1] == ' ' || entered_data[i + 1] == ',')
                count++;
        }
    }
    if (count == 0 || count == 1)
        return 0;
    else
        return 1;
}

int sixth_fault(int comma, int right_bracket, string entered_data)
{
    for (int i = comma + 1; i < right_bracket; i++) {
        if (entered_data[i] >= '0' && entered_data[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

int seventh_fault(int comma, int right_bracket, string entered_data)
{
    for (int i = comma + 1; i < right_bracket; i++) {
        if (entered_data[i] == '-')
            return 0;
    }
    return 1;
}

int eighth_fault(int comma, int right_bracket, string entered_data)
{
    for (int i = comma + 1; i < right_bracket; i++) {
        if ((entered_data[i] >= '0' && entered_data[i] <= '9') || entered_data[i] == '.' || entered_data[i] == ' ')
            continue;
        else
            return 0;
    }
    return 1;
}

int ninth_fault(int left_bracket, int right_bracket, string entered_data)
{
    int count = 0;

    for (int i = left_bracket + 1; i < right_bracket; i++) {
        if (count > 1)
            return 0;
        if (entered_data[i] == ',' || entered_data[i] == ')' || entered_data[i] == '(')
            count++;
        if ((entered_data[i] >= '0' && entered_data[i] <= '9') || entered_data[i] == '-' || entered_data[i] == ',' || entered_data[i] == ' ' || entered_data[i] == '.')
            continue;
        else
            return 0;
    }
    return 1;
}

int tenth_fault(int right_bracket, char numbering[])
{
    for (int i = right_bracket + 2; i < 80; i++) {
        if (numbering[i] == ' ')
            continue;
        else
            return 0;
    }
    return 1;
}
