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



int main(){
    test_init();
    test_alloc();
    test_reset();
    test_addChunk();

    cout << "All tests passed\n";
    return 0;
}