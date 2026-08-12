#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <cstddef>
#include <initializer_list>


template<typename T>
class MyVector{
public:
    ~MyVector(){
        delete[] data;
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
        We use pass by value so it attempts to construct
        the object in call site of the function and any exceptions
        would happen here before the function body execution
        solving any data corruption issues 
    */
    MyVector& operator=(MyVector other){
        swap(this->data, other.data);
        swap(this->size, other.size);
        swap(this->capacity, other.capacity);        

        return *this;
    }

    // Optimized copy assignment
    MyVector& operator=(const MyVector& other){
        if (this == &other) return *this;

        if (other.size <= capacity){
            for (size_t i{}; i < size; ++i){
                data[i] = other.data[i];
            }
            size = other.size;
            return *this;

        } else {
            T* newData = new T[other.capacity];
            for (size_t i{}; i < size; ++i){
                newData[i] = other.data[i];
            }
            delete[] data;
            data = newData;
            size = other.size;
            capacity = other.capacity;


        }
        return *this;
    }

    
    // Move constructor 
    MyVector(MyVector&& other) noexcept
        : data(other.data),
        capacity(other.capacity),
        size(other.size){
            other.data = nullptr
            other.capacity = 0;
            other.size = 0;
        }
        


    // Move assignment for a = b
    MyVector& operator=(MyVector&& other) noexcept{
        if (&other == this) return *this;

        delete[] data;

        size = other.size;
        capacity = other.capacity;
        data = other.data;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;

        return *this;
    }

    //initalizer list
    MyVector(std::initializer_list<int> input){
        size = input.size();
        capacity = size * 2;
        data = new T[size];

        for (int i{}; i < size; ++i){
            data[i] = input[i];
        }
    }

    //If T is not default constructible this will no compile
    // Need to alocate and construct elements manually
    MyVector(std::initializer_list<T> input) 
        : size(input.size())
        , capacity(input.size() * 2){
        
            data = new T[capacity];
            for (int i{}; i < input.size(); ++i){
                data[i] = input[i];
            }
    }

    //initalizer list assignment
    MyVector& operator=(std::initializer_list<T> input){
        delete[] data;
        size = input.size();
        capacity = input.size() * 2;
        data = new T[capacity];


        for (size_t i{}; i < size; ++i){
            data[i] = input[i];
        }

        return *this;
    }


    size_t getSize(){ return size; }
    size_t getCapacty(){ return capacity; }

    T& operator[](size_t index){ return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

private:
    T* data = nullptr;
    size_t size{};
    size_t capacity{};


};


#endif