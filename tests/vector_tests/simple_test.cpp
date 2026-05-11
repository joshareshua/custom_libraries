#include "../bits/stdc++.h"
#include "MyVector.h"

using namespace std;

void test_copy(){
    MyVector a = {1,2,3,4,5};
    MyVector b = a;
    
    //test size
    assert(a.getSize() == b.getSize());

    //test capacity
    assert(a.getCapacity() == b.getCapacity());

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
   size_t prevCapacity = b.getCapacity();
   b = a;

   assert(b.getCapacity() == prevCapacity);
   assert(b.getSize() == a.getSize());
   for (size_t i{}; i < b.getSize(); ++i){
        assert(b.getData()[i] == a.getData()[i]);
   }

   assert(b.getData() != a.getData());
   b.getData()[3] = 100;
   assert(b.getData()[3] != a.getData()[3]);


    //test copy assignment for if capacity is greater then so we create new memory

}

void test_move(){
    /*1. capacity and size should be the same
     2. values should be the same
     3. test the other object has been reset
    */

   MyVector b = {100,101,102,103, 104, 105,106};
   MyVector temp = b;
   MyVector a = std::move(b);
   assert(a.getSize() == temp.getSize());
   assert(a.getCapacity() == temp.getCapacity());
   for (size_t i{}; i < a.getSize(); ++i){
      assert(a.getData()[i] == temp.getData()[i]);
   }

   assert(b.getData() == nullptr);
   assert(b.getSize() == 0);
   assert(b.getCapacity() == 0);


}

void test_move_assignment(){
    MyVector a{1,2,3,4,5};
    MyVector temp = a;

    MyVector b{10,9,8,7};
    b = std::move(a);

    assert(b.getSize() == temp.getSize());
    assert(b.getCapacity() == temp.getCapacity());

    for (size_t i{}; i < b.getSize(); ++i){
        assert(b.getData()[i] == temp.getData()[i]);
    }

    assert(b.getData() != a.getData());
    assert(a.getSize() == 0);
    assert(a.getCapacity() == 0);
    assert(a.getData() == nullptr);
}

void test_initalizer_list(){
    initializer_list<int> in = {1,2,3,4,5};
    MyVector a(in);
    assert(a.getSize() == in.size());
    assert(a.getCapacity() == in.size());

    int index{};
    for (const auto& x : in){
        assert(a.getData()[index++] == x);
    }
}



int main(){
    test_copy();
    test_copy_assignment();
    test_move();
    test_move_assignment();
    test_initalizer_list();
    cout << "All tests have passed\n";

    return 0;
}