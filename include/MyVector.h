#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <memory>
#include <new>
#include <optional>


template<typename T,
    typename Allocator = std::allocator<T>>
class MyVector{
public:
    ~MyVector () noexcept {
        for (size_t i{}; i < size; ++i){
           std::destroy_at(data + i);
        }

        ::operator delete(data); //free memory back to OS/pool
    }

    //C++23 deducing this to reduce code bloat
    template <typename Self>
    size_t getSize(this Self&& self){
        return self.size;
    }

    
    T* getData() {return data;}

    const T* getData() const{return data;}

    std::optional<T&> at(size_t index){
        if (index >= size) return std::nullopt;

        return data[index];
    }

    bool empty() const { return size == 0; }


    template <typename Self>
    size_t getCapacity(this Self&& self){
        return self.capacity;
    }
     
    
    T* begin(){return data;}
    const T* begin() const {return data;} 

    T* end() { return data + size;}
    const T* end() const {return data + size;}

    //default constructor tbd...


    //size based constructor tbd...
    
    // Copy constructor for MyVector a = b where a = *this and b = other;
    MyVector(const MyVector& other) :
        capacity(other.capacity),
        size(other.size) {

        data = static_cast<T*>(::operator new(capacity * sizeof(T)));

        for (size_t i{}; i < size; ++i){
            std::construct_at(data + i, other.data[i]);
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
            T* newData = static_cast<T*>(::operator new(capacity * sizeof(T)));
            for (size_t i{}; i < size; ++i){
                newData[i] = construct_at(data[i], other.data[i]);
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
            other.data = nullptr;
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

    //If T is not default constructible this will no compile
    // Need to alocate and construct elements manually
    MyVector(std::initializer_list<T> input) 
        : size(input.size())
        , capacity(input.size() * 2){
        
            data = static_cast<T*>(::operator new(sizeof(T) * capacity));
            for (int i{}; i < input.size(); ++i){
                construct_at(data + i, input[i]);
            }
    }

    //initalizer list assignment
    //need to improve for better exception guarantee
    //need to reallocate if capacity not enough
    MyVector& operator=(std::initializer_list<T> input){
        
        for (size_t i{}; i < size; ++i){
            destroy_at(data + i);
            
        }
        
        ::operator delete(data);

        size = input.size();
        capacity = input.size() * 2;
        data = static_cast<T*>(::operator new(sizeof(T) * capacity));


        for (size_t i{}; i < size; ++i){
            construct_at(data + i, input[i]);
        }

        return *this;
    }


    T& operator[](size_t index){ return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

    void push_back(const T& value){
        if (size == capacity){
            reserve(capacity == 0? 1: capacity);

        }
        construct_at(data + size, value);
        ++size;
    }

    void reserve(){
        //tbd...
    }

    void pop_back(){
        if (size == 0) return;
        std::destroy_at(data + size - 1);
        --size;
    }

    void clear(){
        if (size == 0) return;
        for (size_t i{}; i < size; ++i){
            destroy_at(data + i);
        }

        size = 0;
    }

    T& front(){
        if (size == 0){
            throw std::out_of_range("MyVector::front called on empty vector");
        }
        return data[0];
    }

    T& back(){
        if (size == 0){
            throw std::runtime_error("No valid elements exist.");
        }
        return data[size-1];
    }


private:
    T* data = nullptr;
    size_t size{};
    size_t capacity{};
};



#endif