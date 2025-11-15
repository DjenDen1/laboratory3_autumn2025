#ifndef ELEMENTMONOLINKEDLIST_H
#define ELEMENEMONOLINKEDLIST_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <type_traits>


std::string transforHEX1(int number);
std::string transforHEXdouble1(double number);
std::string transforBIN1(int number);
std::string transforBINdouble1(double number);

struct MLLE
{
    double double_number;
    int integer_number;
    double integer_number_fractional_part;

    std::string integerHEX;
    std::string doubleHEX;
    std::string integerBIN;
    std::string doubleBIN;
    MLLE* right_forward_prt = nullptr;
    //MLLE* left_back_prt = nullptr;

    MLLE(double value = 0.0) : double_number(value)
    {
        integer_number = static_cast<int>(double_number);
        integer_number_fractional_part = double_number - integer_number;

        integerHEX = transforHEX1(integer_number);
        doubleHEX = transforHEXdouble1(double_number);
        integerBIN = transforBIN1(integer_number);
        doubleBIN = transforBINdouble1(double_number);
    }
    
};

#endif
