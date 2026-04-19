#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <cstddef>
#include <initializer_list>


class MyVector{
    int* data;
    size_t size;
    size_t capacity;

public:
    ~MyVector();

    size_t getSize();

    int* getData();

    size_t getCapacity();
    
    // Copy constructor for MyVector a = b where a = *this and b = other;
    MyVector(const MyVector& other);

    // Copy assignment or a = b where a = *this and b = other;
    MyVector& operator=(const MyVector& other);
    
    // Move constructor 
    MyVector(MyVector&& other) noexcept;


    // Move assignment for a = b
    MyVector& operator=(MyVector&& other) noexcept;

    //initalizer list
    MyVector(std::initializer_list<int> input);

    //initalizer list assignment
    MyVector& operator=(std::initializer_list<int> input);

    void print();


};


#endif