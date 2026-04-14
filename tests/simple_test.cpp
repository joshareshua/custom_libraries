#include "../bits/stdc++.h"
#include "../myVector.cpp"

using namespace std;

bool simple_copy(){
    MyVector a = {1,2,3,4,5};
    MyVector b = a;
    size_t sizeA = a.getSize();
    int* dataA = a.getData(), *dataB = b.getData();
    for (size_t i{}; i < sizeA; ++i){
        if (dataA[i] != dataB[i]) return false;
    }
    return true;

}

int main(){
    if (simple_copy()) cout << "Simple copy test passed!\n";
    else if (!simple_copy()) cout << "Simple copy test failed\n";

    return 0;
}