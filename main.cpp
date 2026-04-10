#include "bits/stdc++.h"
#include "myVector.cpp"

using namespace std;

int main(){
    MyVector a({1,2,3});
    MyVector b = a;

    a.print(); 
    cout << '\n';
    b.print();
    cout << '\n';
    MyVector c({9,8,7});
    b = c;
    b.print();



}