#include "bits/stdc++.h"
#include "../include/MyVector.h"

using namespace std;



    MyVector::~MyVector(){
        delete[] data;
    }

    size_t MyVector::getSize(){
        return size;
    }

    int* MyVector::getData(){
        return data;
    }

    size_t MyVector::getCapacty(){
        return capacity;
    }
    
    // Copy constructor for MyVector a = b where a = *this and b = other;
    MyVector::MyVector(MyVector& other){
        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (size_t i{}; i < size; ++i){
            data[i] = other.data[i];
        }
    }

    // Copy assignment or a = b where a = *this and b = other;
    MyVector& MyVector::operator=(MyVector& other){
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
    Myvector::MyVector(MyVector&& other) noexcept
        : data(other.data),
        capacity(other.capacity),
        size(other.size)
    {
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }  


    // Move assignment for a = b
    MyVector& MyVector::operator=(MyVector&& other) noexcept {
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
    MyVector::MyVector(initializer_list<int> input){
        size = input.size();
        capacity = input.size();
        data = new int(size);
        int index{};
        for (auto x : input){
            data[index++] = x;
        }
    }

    //initalizer list assignment
    MyVector& MyVector::operator=(initializer_list<int> input){
        this->size = input.size();
        this->capacity = input.size();
        data = new int[capacity];
        
        int index{};
        for (auto &in: input){
            data[index] = in;
            ++index;
        }
        
        return *this;
    }

    void MyVector::print(){
        for (size_t i{}; i < size; ++i){
            cout << data[i] << '\t';
        }
        cout << '\n';
    }

