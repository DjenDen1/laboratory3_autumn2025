#ifndef NEWCONTAINER_H
#define NEWCONTAINER_H

#include <iostream>
#include <stdexcept>

template<typename uniqtype>
class LargeNEWcontainer
{
    private:
        uniqtype* data;
        size_t size;
        size_t capacity;
        double growth;

        void grow()
        {
            size_t newCapacity = static_cast<size_t>(capacity * growth);
            if(newCapacity == capacity) newCapacity++;
            uniqtype* NewData = new uniqtype[newCapacity];

            for(size_t index = 0;index < size;index++) NewData[index] = data[index];

            delete[] data;
            data = NewData;
            capacity = newCapacity;

        }
    public: LargeNEWcontainer(size_t initialCapacity = 4 , double growthFactor = 1.5) : size(0) , capacity(initialCapacity), growth(growthFactor)
    {
        data = new uniqtype[capacity];
    }

    ~LargeNEWcontainer()
    {
        delete[] data;
    }

    void push_back(const uniqtype& value)
    {
        if(size >= capacity) grow();
        data[size++] = value;
    }

    class iterator {
        uniqtype* ptr;

        public: iterator(uniqtype* p) : ptr(p) {}

        uniqtype& operator*() {return *ptr;}
        iterator& operator++(){ptr++; return *this;}
        bool operator!=(const iterator& other) const {return ptr != other.ptr;}

    };

    iterator begin()
    {
        return iterator(data);
    }
    iterator end()
    {
        return iterator(data+size);
    }
        
    uniqtype& operator[](size_t index)
    {
        if(index >= size) throw std::out_of_range("Index out of range");
    
        return data[index];
    }

     LargeNEWcontainer& operator=(const LargeNEWcontainer& other) {
        if (this == &other) return *this;

        delete[] data;

        size = other.size;
        capacity = other.capacity;
        growth = other.growth;

        data = new uniqtype[capacity];
        for (size_t i = 0; i < size; i++)
            data[i] = other.data[i];

        return *this;
    }

    size_t getsize() const {return size;}
    size_t getCapacity() const {return capacity;}
};


#endif