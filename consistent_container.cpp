#include "consistent_container.h"
#include <type_traits>
#include <string>
#include <sstream>
std::string transfor_HEX_CE(int number)
{
  
    
    
    if (number == 0) {
        return "0";
    }
    
    std::string HEXnumber = "";
    
    bool isNegative = false;
    if (number < 0) {
        isNegative = true;
        number = -number;
    }
    
    while (number > 0)
    {
        auto exp_number = number % 16;
        std::string letter;
        
        if (exp_number >= 10)
        {
            switch (exp_number) {
                case 10: letter = "A"; break;
                case 11: letter = "B"; break;
                case 12: letter = "C"; break;
                case 13: letter = "D"; break;
                case 14: letter = "E"; break;
                case 15: letter = "F"; break;
            }
        }
        else
        {
            letter = std::to_string(exp_number);
        }
        
        HEXnumber = letter + HEXnumber;
        number = number / 16;
    }
    
    if (isNegative) {
        HEXnumber = "-" + HEXnumber;
    }
    
    return HEXnumber;
}

/*
std::string transforHEX(int number)
{
    std::ostringstream os;
    os << std::hex << number;
    return os.str();
}
*/
std::string transfor_HEX_double_CE(double number)
{
    std::stringstream ss;
    ss << std::hexfloat << number;
    return ss.str();
}

std::string transfor_BIN_CE(int number)
{
    std::string BINnumber = "";
    while(number > 0)
    {
        std::string exp_number = std::to_string(number%2);
        BINnumber = exp_number + BINnumber;
        number = number/2;
    }
    return BINnumber;
}
std::string transfor_BIN_double_CE(double number)
{
    unsigned long long bits;
    std::memcpy(&bits,&number,sizeof(number));
    std::bitset<64> binary(bits);
    return binary.to_string();

}