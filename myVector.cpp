#include "bits/stdc++.h"

using namespace std;


class MyVector{
    int* data;
    size_t size;
    size_t capacity;

public:
    ~MyVector(){
        delete[] data;
    }
    
    // Copy constructor for MyVector a = b where a = *this and b = other;
    MyVector(MyVector& other){
        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (size_t i{}; i < size; ++i){
            data[i] = other.data[i];
        }
    }

    // Copy assignment or a = b where a = *this and b = other;
    MyVector& operator=(MyVector& other){
        if (this == &other) return *this;

        if (other.capacity <= capacity){
            for (size_t i{}; i < other.size; ++i){
                data[i] = other.data[i];
            }

        } else{
            
            int* newData = new int[other.capacity];

            for (size_t i{}; i < other.size; ++i){
                newData[i] = other.data[i];
            }
            delete[] data;
            data = newData;
            capacity = other.capacity;
        }

        size = other.size; 
        return *this;
    }

    // Move constructor 
    MyVector(MyVector&& other) noexcept
        : data(other.data),
        capacity(other.capacity),
        size(other.size)
    {
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }  


    // Move assignment for a = b
    MyVector& operator=(MyVector&& other) noexcept {
        if (this == &other) return *this;

        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = other.data;

        other.size = 0;
        other.capacity = 0;
        other.data = nullptr;

        return *this;
    }

    //initalizer list
    MyVector(initializer_list<int> input){
        size = input.size();
        capacity = input.size();
        data = new int(size);
        int index{};
        for (auto x : input){
            data[index++] = x;
        }
    }

    //initalizer list assignment
    MyVector& operator=(initializer_list<int> input){
        //tbd...
        return *this;
    }


};

int main(){



}