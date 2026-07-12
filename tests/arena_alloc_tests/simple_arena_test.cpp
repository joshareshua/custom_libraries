#include "../../bits/stdc++.h"
#include "../../include/arena_alloc.h"

using namespace std;

void test_init(){
    // testing initalizing allocator and allocating bytes
    ArenaAlloc A(4);
    A.allocate(100);
    assert(A.capacity() == 100/4);

}

void test_alloc(){
    ArenaAlloc A(4);
    A.allocate(100);
    assert(A.used() == 400);
}

void test_reset(){
    ArenaAlloc A(4);
    A.allocate(100);
    A.reset();
    assert(A.used() == 0);
}

void test_addChunk(){
    ArenaAlloc A(4);
    A.allocate(100);
    assert(A.capacity() == 25);
    A.allocate(400);
    assert(A.capacity() == 100);
}

void test_addChunk_edge(){
    //tbd...
}

void test_allocate_returns_valid_pointer(){
    //tbd...
}

void test_alignment(){
    //tbd...
}

void test_invalid_size_throws(){
    //tbd...
}

void test_reuses_freed_memory(){
    //tbd...
}

void test_expands_when_full(){
    //tbd...
}

void test_alloc_edge(){
    ArenaAlloc A(4);
    bool negativeNumber = false;
    try{
        A.allocate(static_cast<std::size_t>(-1));
    } catch (const std::invalid_argument& ){
        negativeNumber = true;
    }

    bool invalidInput = false;
    try{
        A.allocate('5');
        A.allocate('g');
        A.allocate('X');
        A.allocate('a');
    } catch(const std::invalid_argument&){
        invalidInput = true;
    }



    assert(negativeNumber);
    assert(invalidInput);
}



int main(){
    test_init();
    test_alloc();
    test_reset();
    test_addChunk();

    cout << "All tests passed\n";
    return 0;
}