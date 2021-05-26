#include "libgeometry/computation.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

double computation_area(int comma, int right_bracket, string entered_data) {
  int count = 0;
  double area = 0, PI = 3.141592653589793;
  char radius[80];

  for (int i = comma + 1; i < right_bracket; i++) {
    if (entered_data[i] == '-' || entered_data[i] == ' ')
      continue;
    else if ((entered_data[i] >= '0' && entered_data[i] <= '9') ||
             entered_data[i] == '.') {
      radius[count] = entered_data[i];
      count++;
    } else {
      break;
    }
  }

  return area = PI * atof(radius) * atof(radius);
}

double computation_perimeter(int comma, int right_bracket,
                             string entered_data) {
  int count = 0;
  double perimeter = 0, PI = 3.141592653589793;
  char radius[80];

  for (int i = comma + 1; i < right_bracket; i++) {
    if (entered_data[i] == '-' || entered_data[i] == ' ')
      continue;
    else if ((entered_data[i] >= '0' && entered_data[i] <= '9') ||
             entered_data[i] == '.') {
      radius[count] = entered_data[i];
      count++;
    } else {
      break;
    }
  }

  return perimeter = 2 * PI * atof(radius);
}
