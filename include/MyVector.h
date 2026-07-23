#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <cstddef>
#include <initializer_list>


template<typename T>
class MyVector{
public:
    ~MyVector(){
        delete data;
    }

    size_t getSize(){
        return size;
    }

    T* getData(){
        return data;
    }

    size_t getCapacity(){
        return capacity;
    }
    
    // Copy constructor for MyVector a = b where a = *this and b = other;
    MyVector(const MyVector& other){
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];

        for (size_t i{}; i < size; ++i){
            data[i] = other.data[i];
        }
    }

    // Copy assignment or a = b where a = *this and b = other;
    MyVector& operator=(MyVector other){
        swap(this->data, other.data);
        swap(this->size, other.size);
        swap(this->capacity, other.capacity);        

        return *this;
    }
    
    // Move constructor 
    MyVector(MyVector&& other) noexcept;


    // Move assignment for a = b
    MyVector& operator=(MyVector&& other) noexcept;

    //initalizer list
    MyVector(std::initializer_list<int> input);

    //initalizer list assignment
    MyVector& operator=(std::initializer_list<int> input);

    void print();


private:
    T* data;
    size_t size;
    size_t capacity;


};


#endif