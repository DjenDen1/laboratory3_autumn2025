#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

#include "voidprint.h"

#include <list>
#include <vector>
#include <forward_list>
#include <deque>


void containers()
{
     
    std::cout << prinl() <<  " работа с удалением " << prinl() << std::endl;

    std::cout << std::endl;

    std::list<int> list_type1 = {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> vector_type2 = {0,1,2,3,4,5,6,7,8,9};
    std::forward_list<int> forward_list_type3 ={0,1,2,3,4,5,6,7,8,9};
    std::deque<int> deque_type4 = {0,1,2,3,4,5,6,7,8,9};

        std::cout <<"list_type1 в первоначальном виде: ";
        for(int value : list_type1)
        {
            std::cout<<value << " ";
        }


        std::cout << std::endl;
        std::cout << std::endl;


    list_type1.remove(2);
    list_type1.remove(4);
    list_type1.remove(6);


        std::cout <<"list_type1 после удаления элементов (использования метода remove): ";
        for(int value : list_type1)
        {
            std::cout<<value << " ";
        }
        
        
        std::cout << std::endl;
        std::cout << "---";
        std::cout << std::endl;
        
        
        std::cout <<"vector_type2 в первоначальном виде: ";
        for(int value  = 0 ; value < vector_type2.size();value++)
        {
            std::cout << vector_type2[value] << " ";
        }


    vector_type2.erase(vector_type2.begin()+2);
    vector_type2.erase(vector_type2.begin()+4);
    vector_type2.erase(vector_type2.begin()+7); //??


        std::cout << std::endl;
        std::cout << std::endl;


        std::cout <<"vector_type2 после удаления элементов (использования метода erase): ";
        for(int value = 0 ; value < vector_type2.size();value++)
        {
            std::cout << vector_type2[value] << " ";
        }


        std::cout << std::endl;
        std::cout << "---";
        std::cout << std::endl;


        std::cout<< "forward_list_type3 в первоначальном виде: ";
        for(auto value : forward_list_type3)
        {
            std::cout << value << " ";
        }


        std::cout << std::endl;
        std::cout << std::endl;


    forward_list_type3.remove(2);
    forward_list_type3.remove(4);
    forward_list_type3.remove(6);


        std::cout << "forward_list_type3 после удаления в виде: ";
        for(auto value : forward_list_type3)
        {
            std::cout << value << " ";
        }


        std::cout << std::endl;
        std::cout << "---";
        std::cout << std::endl;


        std::cout<<"deque_type4 в первоначальном в виде :";
        for(size_t index = 0; index < deque_type4.size();index++)
        {
            std::cout << deque_type4[index] <<" ";
        }

        std::cout << std::endl;
        std::cout << std::endl;;


    deque_type4.erase(deque_type4.begin()+2);
    deque_type4.erase(deque_type4.begin()+4);
    deque_type4.erase(deque_type4.begin()+6);


       std::cout << "deque_type4 после удаления :"; 
        for(size_t index = 0; index < deque_type4.size();index++)
        {
            std::cout << deque_type4[index] << " ";
        }

    
        std::cout << std::endl;
        std::cout << std::endl;


        std::cout << prinl() <<" работа со вставкой " <<prinl()<<std::endl ;
    
        
        std::cout << std::endl;
        std::cout << std::endl;


        std::cout <<"list_type1 в первоначальной виде: ";
        for(int value : list_type1)
        {
            std::cout<<value << " ";
        }
        
        
        std::cout << std::endl;
        std::cout << std::endl;


   // auto it = list_type1[list_type1[(sizeof(list_type1)/sizeof(list_type1[list_type1.begin()])/2)]];
    auto it1 = std::next(list_type1.begin(),list_type1.size()/2);
    list_type1.insert(it1,20);

        std::cout <<"list_type1 после вставки 20 : ";
        for(int value : list_type1)
        {
            std::cout<<value << " ";
        }

        std::cout << std::endl;
        std::cout << "---";
        std::cout << std::endl;

        std::cout <<"vector_type2 в первоначальном виде: ";
        for(int value  = 0 ; value < vector_type2.size();value++)
        {
            std::cout << vector_type2[value] << " ";
        }

        std::cout << std::endl;
        std::cout << std::endl;

  //  auto it1 = vector_type2.insert(++vector_type2.begin(),5);
  //vector_type2.insert(it1,20);

        auto it2 = std::next(vector_type2.begin(),vector_type2.size()/2);
        vector_type2.insert(it2,20);
        
        std::cout <<"vector_type2 после вставки 20 : ";
        for(int value  = 0 ; value < vector_type2.size();value++)
        {
            std::cout << vector_type2[value] << " ";
        }
        
        std::cout << std::endl;
        std::cout << "---";
        std::cout << std::endl;

        std::cout << "forward_list_type3 в первоначальной виде: ";
        for(auto value : forward_list_type3)
        {
            std::cout << value << " ";
        }


        size_t size = std::distance(forward_list_type3.begin(),forward_list_type3.end());
        auto it3 = std::next(forward_list_type3.begin(),size/2);
        forward_list_type3.insert_after(it3,20);


        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "forward_list_type3 после вставки 20: ";
        for(auto value : forward_list_type3)
        {
            std::cout << value << " ";
        }


        std::cout << std::endl;
        std::cout << "---" << std::endl;
        std::cout << std::endl;


        std::cout << "deque_type4 в первоначальной виде :";
        for(auto value : deque_type4 )
        {
            std::cout << value << " ";
        }


        std::cout << std::endl;
        std::cout << std::endl;


    auto it4 = std::next(deque_type4.begin(),deque_type4.size()/2);
    deque_type4.insert(it4,20);


        std::cout << "deque_type4 после вставки 20 :";
        for(auto value : deque_type4)
        {
            std::cout << value << " ";
        }

}



#endif