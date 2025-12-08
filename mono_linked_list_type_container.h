#ifndef MONO_LINKED_LIST_TYPE_CONTAINER_H
#define MONO_LINKED_LIST_TYPE_CONTAINER_H

#include <iostream>
#include <stdexcept>
#include <bitset>
#include <cstring>
#include <limits>

std::string transfor_HEX_MLE(int number);
std::string transfor_HEX_double_MLE(double number);
std::string transfor_BIN_MLE(int number );
std::string transfor_BIN_double_MLE(double number);

class mono_propert_list_type_container
{
private:
    struct MLE
    {
        double double_number;
        int integer_number;
        double integer_number_fractional_part;
        float floater_number;
        unsigned int unsign_number;
        std::string integerBIN;
        std::string doubleBIN;
        std::string integerHEX;
        std::string doubleHEX;

        MLE* step_forward;


    

    MLE(double value = 0.0 ): double_number(value) , step_forward(nullptr)
    {
        integer_number = static_cast<int>(double_number);
        integer_number_fractional_part = double_number - integer_number;

        floater_number = static_cast<float>(double_number);
        unsign_number = integer_number;

        integerHEX = transfor_HEX_MLE(integer_number);
        doubleHEX = transfor_HEX_double_MLE(double_number);
        integerBIN = transfor_BIN_MLE(integer_number);
        doubleBIN = transfor_BIN_MLE(double_number);

    }
    
    unsigned long int size_sctructMLE()
    {
        auto  auto_size = sizeof(double_number)
                  + sizeof(doubleBIN)
                  + sizeof(doubleHEX)
                  + sizeof(floater_number)
                  + sizeof(integer_number)
                  + sizeof(integer_number_fractional_part)
                  + sizeof(integerBIN)
                  + sizeof(integerHEX)
                  + sizeof(unsign_number);
        return auto_size;
    }

    };

    MLE* head;
    MLE* tail;
    size_t size_container;

public:
    mono_propert_list_type_container() : head(nullptr) , tail(nullptr) , size_container(0) {}

    ~mono_propert_list_type_container()
    {
        MLE* cur = head;
        while (cur)
        {
            MLE* next = cur-> step_forward;
            delete cur;
            cur = next;
        }
    }

    class list_type_iterator
    {

        public:
            MLE* ptr;
            list_type_iterator(MLE* p = nullptr) : ptr(p) {}

            MLE& operator*() {return *ptr;} 
            MLE* operator->(){return ptr;}

            list_type_iterator& operator++()
            {
                if (ptr) ptr = ptr->step_forward;
                return *this;
            }

            bool operator!=(const list_type_iterator& other ) const {return ptr != other.ptr;}

    };

    list_type_iterator begin() {return list_type_iterator(head);}
    list_type_iterator end() {return list_type_iterator(nullptr);}

    void push_back(double value)
    {
        MLE* node = new MLE(value);

        if(head == nullptr)
        {
            head = tail = node;
        }
        else
        {
            tail->step_forward = node;
            tail = node;
        }

        size_container++;
    }

    size_t size() const {return size_container;}
    unsigned long int containersize()
    {
        unsigned long int total = 0;
        MLE* cur = head;
        while(cur != nullptr)
        {
            total += cur->size_sctructMLE();
            cur = cur->step_forward;
        }
        return total;
    }

    void erase(double value)
    {
        MLE* current = head;
        MLE* prev = current;
        while(current != nullptr)
        {
            if(current->double_number == value)
            {
                if (current == head && current == tail)
                {
                    head = tail = nullptr;
                }
                else if (current == head)
                {
                    head = head->step_forward;
                }
                else if (current == tail)
                {
                    tail = prev;
                    if(tail) tail->step_forward = nullptr;
                }
                else
                {
                    prev -> step_forward = current->step_forward;
                }

                MLE* to_delete = current;
                current = current->step_forward;
                delete to_delete;
                size_container--;

                if(prev && prev->step_forward == to_delete)  prev->step_forward = current;

                break;
            }
            else
            {
                prev = current;   
                current = current->step_forward;
            }
        }
    }

   void insert(list_type_iterator pos, double value)
{
    MLE* new_node = new MLE(value);
    
    if (pos.ptr == nullptr) // Вставка в конец
    {
        if(tail == nullptr)
        {
            head = tail = new_node;
        }
        else
        {
            tail->step_forward = new_node;
            tail = new_node;
        }
        size_container++;
        return;
    }
    
    if(pos.ptr == head) // Вставка перед головой
    {
        new_node->step_forward = head;
        head = new_node;
        size_container++;
        return;
    }
    
    // Вставка в середину
    MLE* current = head;
    MLE* prev = nullptr;
    
    while(current != nullptr && current != pos.ptr)
    {
        prev = current;
        current = current->step_forward;
    }
    
    if(prev)
    {
        prev->step_forward = new_node;
        new_node->step_forward = current;
        size_container++;
    }
}

};

#endif
