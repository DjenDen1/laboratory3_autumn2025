#include "voidprint.h"
#include "elementdoublelinkedlist.h"
#include "functions.h"
#include "newcontainer.h"
#include "containers.h"
#include <iostream>

#include "list_type_container.h"
#include "consistent_container.h"

#include <cstdlib>
#include <list>
#include <vector>
#include <forward_list>
#include <deque>
#include <ctime>
#include <locale>


/*

int main()
{
   setlocale(LC_ALL, "ru-RU.UTF-8");
    std::srand(std::time(nullptr));

    //containers();
        
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
    
    
    if(next_it != double_linked_list.end())
    {
        (*it)->right_forward_ptr = *next_it; 
    }
    else
    {
        (*it)->right_forward_ptr = nullptr; 
    }
    
    if(it != double_linked_list.begin())
    {
        (*it)->left_back_ptr = *prev_it;  
    }
    else
    {
        (*it)->left_back_ptr = nullptr;
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


   propert_consistent_container container1;
   for(int index = 0; index < 20; index++)
   {
      container1.push_back(index*1.2439498599994955);
   }

   propert_list_type_container container2;
   // propert_list_type_container::list_type_iterator it_list = container2.begin(); - оказалось что итератор статический и он будет указывать на тот самый участок памяти, который пустой
   for(int index = 0; index < 20; index++)
   {
    container2.push_back(index);
   }

   int count =0;
   propert_list_type_container::list_type_iterator it_list = container2.begin();

   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << it_list->size_structLE();
    return 0;}
    
*/


int main()
{
    propert_list_type_container list1;
    std::cout << "propert_list_type_container list1;" << std::endl;
    for(size_t index=0; index < 10; index++)
    {
        list1.push_back(index);
    }
    propert_list_type_container::list_type_iterator it_list1 = list1.begin();
    while(it_list1 != list1.end())
    {
        std::cout <<it_list1 ->double_number <<" ";
        ++it_list1;
    }
    std::cout << std::endl;
    list1.erase(2);
    list1.erase(4);
    list1.erase(6);
    propert_list_type_container::list_type_iterator it_list2 = list1.begin();
    while(it_list2 != list1.end())
    {
        std::cout <<it_list2 ->double_number <<" ";
        ++it_list2;
    }
    std::cout << std::endl;
    propert_list_type_container::list_type_iterator it_list3 = list1.begin();
    
    list1.insert(it_list3,10);

        propert_list_type_container::list_type_iterator it_list4 = list1.begin();
    while(it_list4 != list1.end())
    {
        std::cout <<it_list4 ->double_number <<" ";
        ++it_list4;
    }


    propert_list_type_container::list_type_iterator it_list5 = list1.begin();
    size_t mid_index = list1.size()/2;
    for(size_t index = 0; index < mid_index; index++) ++it_list5;
    list1.insert(it_list5,20);

    std::cout << std::endl;

    propert_list_type_container::list_type_iterator it_list6 = list1.begin();
    while(it_list6 != list1.end())
    {
        std::cout <<it_list6 ->double_number <<" ";
        ++it_list6;
    }
    
    std::cout << std::endl;

    propert_list_type_container::list_type_iterator it_list7 = list1.end();
    list1.insert(it_list7,30);

     propert_list_type_container::list_type_iterator it_list8 = list1.begin();
    while(it_list8 != list1.end())
    {
        std::cout <<it_list8 ->double_number <<" ";
        ++it_list8;
    }
    

    propert_consistent_container consistent1;

    for(size_t index = 0; index < 10;index++)
    {
        consistent1.push_back(index);
    }
    for(size_t index =0; index < consistent1.getsize(); index++)
    {
        std::cout << consistent1[index].double_number << " ";
    }
    consistent1.erase(2);
    consistent1.erase(4);
    consistent1.erase(6);
    
    
    return 0;

}