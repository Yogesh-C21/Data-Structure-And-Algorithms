#include<iostream>
using namespace std;

int main()
{
    int a=10;
    cout<<&a<<" ";
    
    int* aPtr;
    aPtr = &a;
    cout<<aPtr<<" is the address of a and the value is "<<*aPtr;
}