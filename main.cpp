#include "voidprint.h"
#include "elementdoublelinkedlist.h"
#include "functions.h"
#include "newcontainer.h"
#include "containers.h"
#include <iostream>

#include <list>
#include <vector>
#include <forward_list>
#include <deque>



int main()
{
   

    containers();
        
    std::cout << prinl() << " работа с двунапавленный контейнером " << prinl() << std::endl;

    std::list<DLLE*> double_linked_list;
    std::list<MLLE*> mono_linked_list;



for(size_t index = 0; index < 10; index++)
{
    DLLE* element = new DLLE(index);
    double_linked_list.push_back(element);
}

for(size_t index = 0; index < 10; index++)
{
    MLLE* element = new MLLE(index);
    mono_linked_list.push_back(element);
}


auto it = double_linked_list.begin();
while(it != double_linked_list.end())
{
    auto next_it = std::next(it);
    auto prev_it = (it == double_linked_list.begin()) ? double_linked_list.end() : std::prev(it);
    
    // Устанавливаем правый указатель (на следующий элемент)
    if(next_it != double_linked_list.end())
    {
        (*it)->right_forward_ptr = *next_it; // Есть следующий элемент
    }
    else
    {
        (*it)->right_forward_ptr = nullptr; // Это последний элемент
    }
    
    // Устанавливаем левый указатель (на предыдущий элемент)
    if(it != double_linked_list.begin())
    {
        (*it)->left_back_ptr = *prev_it; // Есть предыдущий элемент
    }
    else
    {
        (*it)->left_back_ptr = nullptr; // Это первый элемент
    }
    
    ++it;
}

auto it_mono = mono_linked_list.begin();
while(it_mono != mono_linked_list.end())
{
    auto next_it_mono = std::next(it_mono);
    auto prev_it_mono = (it_mono == mono_linked_list.begin() ? mono_linked_list.end() : std::prev(it_mono));
    if(next_it_mono != mono_linked_list.end())
    {
        (*it_mono)->right_forward_prt = *next_it_mono;
    }
    else
    {
        (*it_mono)->right_forward_prt = nullptr;
    }

    ++it_mono;
    
}
   
/*
DLLE* exp = new DLLE(8000.032323);
  
std::cout << "Double: " << exp->double_number << std::endl;
std::cout << "Integer: " << exp->integer_number << std::endl;
std::cout << "Fractional: " << exp->intger_number_fractional_part << std::endl;
std::cout << "Integer HEX: " << exp->integerHEX << std::endl;
std::cout << "Double HEX: " << exp->doubleHEX << std::endl;
std::cout << "integerBIN: " << exp->integerBIN << std::endl;
std::cout << "BINdouble: "  << exp->doubleBIN << std::endl;
*/

   
    intelectual_print(double_linked_list,mono_linked_list);        

    return 0;
}