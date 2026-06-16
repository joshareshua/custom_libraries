#include "../bits/stdc++.h"
#include "../../include/arena_alloc.h"

using namespace std;



void test_init(){
    // testing initalizing allocator and allocating bytes
    ArenaAlloc A(4);
    A.allocate(100);
    assert(A.capacity() == 100/4);

}

int main(){
    return 0;
}