#pragma once
#include <iostream>
#include <string>
using namespace std;

int zero_fault(int left_bracket, int right_bracket);

int first_fault(int CircleTrue);

int second_fault(int comma);

int third_fault(int left_bracket, int comma, string entered_data);

int fourth_fault(int left_bracket, int comma, string entered_data);

int fifth_fault(int left_bracket, int comma, string entered_data);

int sixth_fault(int comma, int right_bracket, string entered_data);

int seventh_fault(int comma, int right_bracket, string entered_data);

int eighth_fault(int comma, int right_bracket, string entered_data);

int ninth_fault(int left_bracket, int right_bracket, string entered_data);

int tenth_fault(int right_bracket, char numbering[]);
