#include "../bits/stdc++.h"
#include "MyVector.h"

using namespace std;


    
    // Copy constructor for MyVector a = b where a = *this and b = other;
  

    // Copy assignment or a = b where a = *this and b = other;
    MyVector& MyVector::operator=(const MyVector& other){
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