#include "../bits/stdc++.h"

using namespace std;

class ArenaAlloc{
public:
    void* allocate(){}

    void reset(){}


private:
    vector<int*> chunks;

};