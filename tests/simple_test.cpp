#include "../bits/stdc++.h"
#include "../src/myVector.cpp"

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

void test_copy_assignment(){}

void test_move(){}

void test_move_assignment(){}

void test_initalizer_list(){}



int main(){
    test_copy();
    cout << "All tests have passed\n";

    return 0;
}