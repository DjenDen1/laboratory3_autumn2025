#ifndef ELEMENTDOUBLELINKEDLIST_H
#define ELEMENTDOUBLELINKEDLIST_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <cstring>
std::string transforHEX(int number);
std::string transofrHEXdouble(double number);
std::string transforBIN(int number);
std::string transforBINdouble(double number);
struct DLLE 
{   
    double double_number;
    int integer_number;
    double  intger_number_fractional_part;  
    
    std::string integerHEX;
    std::string doubleHEX;
    std::string integerBIN;
    std::string doubleBIN;
    DLLE* right_forward_ptr = nullptr;
    DLLE* left_back_ptr = nullptr;

    DLLE(double value= 0.0) : double_number(value)
    {
        integer_number = static_cast<int>(double_number);
        intger_number_fractional_part = double_number - integer_number;  
        integerHEX = transforHEX(integer_number);
        doubleHEX = transofrHEXdouble(double_number);
        integerBIN = transforBIN(integer_number);
        doubleBIN = transforBINdouble(double_number);
    }

};



#endif