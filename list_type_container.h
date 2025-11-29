#ifndef LIST_TYPE_CONTAINER_H
#define LIST_TYPE_CONTAINER_H

#include <iostream>
#include <stdexcept>
#include <bitset>
#include <cstring>
#include <iomanip>
#include <limits>

std::string transfor_HEX_LE(int number);
std::string transfor_HEX_double_LE(double number);
std::string transfor_BIN_LE(int number);
std::string transfor_BIN_double_LE(double number);


class propert_list_type_container
{
private:
    struct LE
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

        LE* step_forward;
        LE* step_back;

   

        LE(double value = 0.0) :  double_number(value), step_forward(nullptr), step_back(nullptr)
        {
            integer_number = static_cast<int>(double_number);
            integer_number_fractional_part = double_number - integer_number;
    
            floater_number = static_cast<float>(double_number);
            unsign_number = integer_number;

            integerHEX = transfor_HEX_LE(integer_number);
            doubleHEX = transfor_HEX_double_LE(double_number);
            integerBIN = transfor_BIN_LE(integer_number);
            doubleBIN = transfor_BIN_double_LE(double_number);
        }

            unsigned long int size_structLE()
            {
            auto all_size = sizeof(double_number) 
                          + sizeof(doubleBIN)
                          + sizeof(doubleHEX) 
                          + sizeof(floater_number) 
                          + sizeof(integer_number)
                          + sizeof(integer_number_fractional_part)
                          + sizeof(integerBIN)
                          + sizeof(integerHEX)
                          + sizeof(unsign_number);
            return all_size;
            }

    };


    LE* head;
    LE* tail;
    size_t size_container;

public:

    propert_list_type_container() : head(nullptr), tail(nullptr), size_container(0) {}

    ~propert_list_type_container()
    {
        LE* cur = head;
        while (cur) {
            LE* next = cur->step_forward;
            delete cur;
            cur = next;
        }
    }


    class list_type_iterator
    {
    private:
        LE* ptr;
    public:
        list_type_iterator(LE* p = nullptr) : ptr(p) {}

        LE& operator*() { return *ptr;} // именно так возвращается элэмент а не адресс , а LE$ operator*() {return ptr;} - вернется сам указатель 
        LE* operator->(){return ptr;}

        list_type_iterator& operator++()
        {
            if (ptr) ptr = ptr->step_forward;
            return *this;
        }

        bool operator!=(const list_type_iterator& other) const { return ptr != other.ptr; }
    };

    list_type_iterator begin() { return list_type_iterator(head); }
    list_type_iterator end() { return list_type_iterator(nullptr); }

    void push_back(double value)
    {
        LE* node = new LE(value);

        if (head == nullptr) 
        {
            head = tail = node;
        } 
        else 
        {
            tail->step_forward = node;
            node->step_back = tail;
            tail = node;
        }

        size_container++;
    }

    size_t size() const { return size_container; }
    unsigned long int containersize()
    {
        unsigned long int total =0;
        LE* cur = head;

        while (cur != nullptr)
        {
            total += cur->size_structLE();
            cur = cur->step_forward;
        }
        return total;
    }

   void erase(double value)
    {
        LE* current = head;
        
        while (current != nullptr)
        {
            if (current->double_number == value)
            {
        
                if (current == head && current == tail)
                {
    
                    head = tail = nullptr;

                }
                else if (current == head)
                {
                    head = head->step_forward;
                    head->step_back = nullptr;
                    
                }
                else if (current == tail)
                {
                    tail = tail->step_back;
                    tail->step_forward = nullptr;
                    
                }
                else
                {
                    current->step_back->step_forward = current->step_forward;
                    current->step_forward->step_back = current->step_back;
                    
                }
                
                LE* to_delete = current;
                current = current->step_forward;
                delete to_delete;
                size_container--;
                break;
            }
            else
            {
                current = current->step_forward;
            }
        }
    }
    void insert(list_type_iterator pos, double value)
{
    LE* new_node = new LE(value);
    LE* current = pos.operator->(); 
  
    if (current == nullptr)
    {
        if (tail == nullptr) 
        {
      
            head = tail = new_node;
        } 
        else 
        {
            tail->step_forward = new_node;
            new_node->step_back = tail;
            tail = new_node;
        }

        size_container++;
        return;
    }

 
    if (current == head)
    {
        new_node->step_forward = head;
        head->step_back = new_node;
        head = new_node;

        size_container++;
        return;
    }

    LE* prev = current->step_back;

    prev->step_forward = new_node;
    new_node->step_back = prev;

    new_node->step_forward = current;
    current->step_back = new_node;

    size_container++;
}

};

#endif
