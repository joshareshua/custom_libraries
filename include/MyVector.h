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
    /*
        We use pass my value so it attempts to construct
        the object in call site of the function and any exceptions
        would happen here before the function body executation
        solving any data corruption issues 
    */
    MyVector& operator=(MyVector other){
        swap(this->data, other.data);
        swap(this->size, other.size);
        swap(this->capacity, other.capacity);        

        return *this;
    }
    
    // Move constructor 
    MyVector(MyVector&& other) noexcept
        : data(other.data),
        capacity(other.capacity),
        size(other.size){
            other.data = 
            other.capacity = 0;
            other.size = 0;
        }
        


    // Move assignment for a = b
    MyVector& operator=(MyVector&& other) noexcept;

    //initalizer list
    MyVector(std::initializer_list<int> input){
        size = input.size();
        capacity = size * 2;
        data = new T[size];

        for (int i{}; i < size; ++i){
            data[i] = input[i];
        }
    }

    //initalizer list assignment
    MyVector& operator=(std::initializer_list<T> input){
        delete[] data;
        size = input.size();
        capacity = input.size();
        data = new T[capacity];


        for (size_t i{}; i < size; ++i){
            data[i] = input[i];
        }

        return this*;
    }


    size_t getSize(){ return size; }
    size_t getCapacty(){ return capacity; }

    T& operator[](size_t index){ return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

private:
    T* data;
    size_t size;
    size_t capacity;


};


#endif