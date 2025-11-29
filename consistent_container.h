#ifndef CONSISTENT_CONTAINER_H
#define CONSISTENT_CONTAINER_H

#include <iostream>
#include <stdexcept>
#include <bitset>
#include <cstring>
#include <iomanip>
#include <limits>

std::string transfor_HEX_CE(int number);
std::string transfor_HEX_double_CE(double number);
std::string transfor_BIN_CE(int number);
std::string transfor_BIN_double_CE(double number);


class propert_consistent_container
{
    private:
    struct CE
    {
        double double_number;
        float floater_number;
        int integer_number;
        double integer_number_fractional_part;
        unsigned int unsign_number;
        std::string integerHEX;
        std::string doubleHEX;
        std::string integerBIN;
        std::string doubleBIN;

        CE(double value = 0.0 ) : double_number(value)
        {
            integer_number = static_cast<int>(double_number);
            floater_number = static_cast<float>(double_number);
            integer_number_fractional_part = double_number - integer_number;

            unsign_number = integer_number;

            integerHEX = transfor_HEX_CE(integer_number);
            doubleHEX = transfor_HEX_double_CE(double_number);
            integerBIN = transfor_BIN_CE(integer_number);
            doubleBIN  = transfor_BIN_double_CE(double_number);

          

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
    CE* data;
    size_t size_container;
    size_t capacity_container;
    double growth;
    

    void grow_container()
    {
        size_t new_capacity = 0;
        if( capacity_container - size_container <= 1)
        {
            new_capacity = static_cast<size_t>(capacity_container * 1.1);
        }
        else if( capacity_container - size_container <= 3)
        {
            new_capacity = static_cast<size_t>(capacity_container * 1.2);
        }
        else
        {
            new_capacity = static_cast<size_t>(capacity_container * growth);
        }
        
        if(new_capacity == capacity_container) new_capacity++;

        CE* new_data = new CE[new_capacity];

        for(size_t index = 0; index < size_container; index++) new_data[index] = data[index];

        delete[] data;
        data = new_data;
        capacity_container = new_capacity;
        
    }

    void shrink_to_fit()
    {
        if(size_container == capacity_container) return;
        size_t new_capacity = capacity_container - static_cast<int>((capacity_container-size_container)/2);

        if (new_capacity < 5 ) new_capacity =5;

        CE* new_data = new CE[new_capacity];

        for(size_t index = 0; index < size_container; index++) new_data[index] = data[index];

        delete[] data;
        data =new_data;
        capacity_container = new_capacity;

    }

    int size_bytes()
    {
        int all_size = 0;
        for(size_t index = 0; index < size_container; index++) all_size+=data[index].size_structLE();
        return all_size;
    }

    void increment_grow()
    {
        size_t new_capacity = capacity_container + 1;

        CE* new_data = new CE[new_capacity];

        for(size_t index = 0; index < size_container; index++) new_data[index] = data[index];

        delete[] data;

        data = new_data;
        capacity_container = new_capacity;
    }


    public: propert_consistent_container(size_t base_capacity = 4 , double growthFactor = 1.5) : size_container(0) , capacity_container(base_capacity) , growth(growthFactor)
    {
        data = new CE[capacity_container];
    }
    
    ~propert_consistent_container()
    {
        delete[] data;
    }

    void push_back(const CE& value)
    {
        if(size_container >= capacity_container) grow_container();
        data[size_container++] = value;
    }

    class consistent_iterator
    {
        CE* ptr;
        
        public: consistent_iterator(CE* p): ptr(p) {}
        
        CE&  operator*() {return *ptr;}
        consistent_iterator&  operator++(){ptr++; return *this;}
        bool operator!=(const consistent_iterator& other) const {return ptr != other.ptr;}

    };

    consistent_iterator begin()
    {
        return consistent_iterator(data);
    }
    consistent_iterator end()
    {
        return consistent_iterator(data+size_container);
    }
    
    CE& operator[](size_t index)
    {
        if(index >= size_container) throw std::out_of_range("Index out");

        return data[index];
    }

    propert_consistent_container& operator=(const propert_consistent_container& other)
    {
        if (this == &other) return *this;
        
        delete[] data;

        size_container = other.size_container;
        capacity_container = other.capacity_container;
        growth = other.growth;

        data = new CE[capacity_container];
        for(size_t index = 0; index < size_container; index++) data[index] = other.data[index];

        return *this;
    }

    size_t getsize() const {return size_container;}
    size_t getcapacity() const {return capacity_container;}

    void modcharacteristic(double number)
    {
        growth = number;
    }


    bool abs_check()
    {
        for(size_t index= 0; index < size_container; index++)
        {
            if (std::abs(data[index].double_number) != data[index].double_number) return false;
        }

        return true;
    }

    int abs_count() const
    {
        int count = 0;
        double largest_negative = -std::numeric_limits<double>::min();
        double smallest_negative = std::numeric_limits<double>::lowest();
        
        for (size_t index = 0; index < size_container; index++) {
            if (data[index].double_number >= smallest_negative && 
                data[index].double_number <= largest_negative) {
                count++;
            }
        }
        return count;
    }

    void erase(size_t index) 
    {
        if (index >= size_container) throw std::out_of_range("Index out");
        
        
        std::copy(data + index + 1, data + size_container, data + index);
        
        size_container--;
        
        if (capacity_container - size_container >= 4)  shrink_to_fit();
    }

    void sp_push_front(double number)
    {
        if(size_container >= capacity_container) increment_grow();

        std::copy_backward(data,data+size_container,data + size_container + 1 );
        data[0] = CE(number);   //data[0] = static_cast<CE>(number); - так как это ПРЕОБРАЗОВАНИЕ , а данная строка инициализация 

        size_container++;
    }
    void sp_insert(int index, double number)
    {
    if (index < 0 || index > size_container) {
        throw std::out_of_range("Index out of range");
    }
    
    if (size_container >= capacity_container) increment_grow();

  
    std::copy_backward(data + index, data + size_container, data + size_container + 1);
    
    data[index] = CE(number);
    
    size_container++;
    }

    void forced_grow()
    {
        grow_container();
    }

    void forced_shrink()
    {
        shrink_to_fit();
    }
    
    
};

#endif