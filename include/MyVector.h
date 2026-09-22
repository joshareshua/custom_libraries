#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <memory>
#include <optional>
#include <utility>
#include <new>
#include<iostream>


template<typename T,
    typename Allocator = std::allocator<T>>
class MyVector{
public:
    ~MyVector () noexcept {
        for (std::size_t i{}; i < size; ++i){
           std::destroy_at(data + i);
        }

        ::operator delete(data); //free memory back to OS/pool
    }

    //default constructor
    MyVector() noexcept = default;

    //C++23 deducing this to reduce code bloat
    template <typename Self>
    std::size_t getSize(this Self&& self){
        return self.size;
    }

    
    T* getData() {return data;}

    const T* getData() const{return data;}

    T* at(std::size_t index){
        return index < size? data + index: throw std::out_of_range("Index out of bounds\n");
    }

    const T* at(size_t index) const{
        return index < size? data + index
                        : throw std::out_of_range("Index out of bounds");
    }

    T* try_at(size_t index) noexcept{
        return index < size? data + index : nullptr;
    }

    const T* try_at(size_t index) const noexcept {
        return index < size? data + index : nullptr;
    }

    bool empty() const { return size == 0; }


    template <typename Self>
    std::size_t getCapacity(this Self&& self){
        return self.capacity;
    }
     
    
    T* begin(){return data;}
    const T* begin() const {return data;} 

    T* end() { return data + size;}
    const T* end() const {return data + size;}


    //size based constructor tbd...
    MyVector(std::size_t inputSize) : size(inputSize), capacity(inputSize){
        size_t constructed{};

        //use temporary constructoin + commit tbd...
        try{
            data = static_cast<T*>(::operator new(capacity * sizeof(T)));
            for (; constructed < size; ++constructed){
                std::construct_at(data + constructed);
            }
        } catch(...){
            
            while (constructed > 0){
                std::destroy_at(data + --constructed);
            
            }
            ::operator delete(data);
            data = nullptr;
            size = 0;
            capacity = 0;
            throw;
        }
    }
    
    // Copy constructor for MyVector a = b where a = *this and b = other;
    MyVector(const MyVector& other) :
        capacity(other.capacity),
        size(other.size) {
        
        std::size_t constructed{};
        try{
            data = static_cast<T*>(::operator new(capacity * sizeof(T)));

            for (; constructed < size; ++constructed){
                std::construct_at(data + constructed, other.data[constructed]);
            }
        } catch (...){
            while (constructed > 0){
                std::destroy_at(data + --constructed);
            }

            ::operator delete(data);
            throw;
        }
    }

    // Copy assignment or a = b where a = *this and b = other;
    /*
        We use pass by value so it attempts to construct
        the object in call site of the function and any exceptions
        would happen here before the function body execution
        solving any data corruption issues 
    
    MyVector& operator=(MyVector other){
        std::swap(this->data, other.data);
        std::swap(this->size, other.size);
        std::swap(this->capacity, other.capacity);        

        return *this;
    }*/
    

    // Need to revise copy assignment for strong exception guarantee
    // Optimized copy assignment
    MyVector& operator=(const MyVector& other){
        if (this == &other) return *this;

        MyVector tmp(other);
        swap(tmp);
        return *this;
    }

    void swap(MyVector& other) noexcept{
        std::swap(data, other.data);
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
    }

    
    // Move constructor 
    MyVector(MyVector&& other) noexcept
        : data(other.data),
        capacity(other.capacity),
        size(other.size){
            other.data = nullptr;
            other.capacity = 0;
            other.size = 0;
        }
        


    // Move assignment for a = b
    MyVector& operator=(MyVector&& other) noexcept{
        if (&other == this) return *this;
        
        //destroy old objects and deallocate old memory
        for (size_t i{}; i < size; ++i){
            std::destroy_at(data + i);
        }
        ::operator delete(data);

        //switch ownership/resources 
        // and leave object switched from in valid state
        size = other.size;
        capacity = other.capacity;
        data = other.data;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;

        return *this;
    }

    //If T is not default constructible this will no compile
    // Need to alocate and construct elements manually
    MyVector(std::initializer_list<T> input) 
        : size(input.size())
        , capacity(input.size() * 2){
        
            data = static_cast<T*>(::operator new(sizeof(T) * capacity));
            for (int i{}; i < input.size(); ++i){
                std::construct_at(data + i, input[i]);
            }
    }

    //initalizer list assignment
    //need to improve for better exception guarantee
    //need to reallocate if capacity not enough
    MyVector& operator=(std::initializer_list<T> input){
        
        for (std::size_t i{}; i < size; ++i){
            std::destroy_at(data + i);
            
        }
        
        ::operator delete(data);

        size = input.size();
        capacity = input.size() * 2;
        data = static_cast<T*>(::operator new(sizeof(T) * capacity));


        for (std::size_t i{}; i < size; ++i){
            std::construct_at(data + i, input[i]);
        }

        return *this;
    }


    T& operator[](std::size_t index){ return data[index]; }
    const T& operator[](std::size_t index) const { return data[index]; }

    void push_back(const T& value){
        if (size == capacity){
            reserve(capacity == 0? 1: capacity * 2);

        }
        std::construct_at(data + size, value);
        ++size;
    }

    void reserve(std::size_t newCap){
        if (newCap <= capacity) return;
        
        if (newCap == capacity) return;

        T* temp = static_cast<T*>(
            ::operator new(newCap * sizeof(T)));

        for (int i{}; i < size; ++i){
            std::construct_at(temp + i, std::move(data[i]));
        }

        std::swap(temp, data);
        capacity = newCap;
        
        for (int i{}; i < size; ++i){
            std::destroy_at(temp + i);
        }

        ::operator delete(temp);
        
    }

    void pop_back(){
        if (size == 0) return;
        std::destroy_at(data + size - 1);
        --size;
    }

    void clear(){
        if (size == 0) return;
        for (std::size_t i{}; i < size; ++i){
            std::destroy_at(data + i);
        }

        size = 0;
    }

    T& front(){
        if (size == 0){
            throw std::out_of_range("MyVector::front called on empty vector.\n");
        }
        return data[0];
    }

    const T& front() const {
        if (size == 0){
            throw std::out_of_range("MyVector::front called on empty vector.\n");
        }
        return data[0];
    }

    T& back(){
        if (size == 0){
            throw std::out_of_range("No valid elements exist.\n");
        }
        return data[size-1];
    }

    const T& back() const {
        if (size == 0){
            throw std::out_of_range("No valid elements exist.\n");
        }
        return data[size-1];
    }


private:
    T* data = nullptr;
    std::size_t size{};
    std::size_t capacity{};
};



#endif