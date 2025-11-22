#include "voidprint.h"

std::string prinl()
{
    std::string longline = " =-=-=-=-=-=-=-=-=-=-=- ";
    return longline;
}

std::string prinequal()
{
    std::string lonline = "===================================";
    return lonline;
}

std::string princhain()
{
    std::string lonline = "//////////////////////////////////////////////////////////";
    return lonline;
}

void printin_triple_block()
{
    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;
}

void printin_double_block()
{
    std::cout << std::endl;
    std::cout << std::endl;
}