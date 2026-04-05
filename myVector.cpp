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
        int *data = new int[capacity];
        for (size_t i{}; i < size; ++i){
            data[i] = other.data[i];
        }
    }

    // Copy assignment or a = b where a = *this and b = other;
    MyVector& operator=(MyVector& other){
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

    // Move constructor and assignment
    MyVector(MyVector&& other){}    
    MyVector& operator=(MyVector&& other){}


};

int main(){



}