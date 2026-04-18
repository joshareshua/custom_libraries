#include "../bits/stdc++.h"
#include "../include/MyVector.h"

using namespace std;

void test_copy(){
    MyVector a = {1,2,3,4,5};
    MyVector b = a;
    
    //test size
    assert(a.getSize() == b.getSize());

    //test capacity
    assert(a.getCapacty() == b.getCapacty());

    //test same values
    for (size_t i{}; i < a.getSize(); ++i){
        assert(a.getData()[i] == b.getData()[i]);
    }

    //test deep copy
    assert(a.getData() != b.getData());

    //test mutation
    a.getData()[0] = 99;
    assert(a.getData()[0] != b.getData()[0]);

}

void test_copy_assignment(){
    MyVector a = {10,9,8,7,6};
    MyVector b = {0,1,2,3,4};
    
    //test the current value of b
    for(size_t i{}; i < b.getSize(); ++i){
        assert(b.getData()[i] == i);
    }

    //test copy assignment for if capacity is less than
    /*1. capacity should be same, 
      2.size is same as a, 3.
      3.values should be same as a now,
      4. test still deep copy
      5. test mutation
    */
   size_t prevCapacity = b.getCapacty();
   b = a;

   assert(b.getCapacty() == prevCapacity);
   assert(b.getSize() == a.getSize());
   for (size_t i{}; i < b.getSize(); ++i){
        assert(b.getData()[i] == a.getData()[i]);
   }

   assert(b.getData() != a.getData());
   b.getData()[3] = 100;
   assert(b.getData()[3] != a.getData()[3]);


    //test copy assignment for if capacity is greater then so we create new memory

}

void test_move(){}

void test_move_assignment(){}

void test_initalizer_list(){}



int main(){
    test_copy();
    test_copy_assignment();
    cout << "All tests have passed\n";

    return 0;
}