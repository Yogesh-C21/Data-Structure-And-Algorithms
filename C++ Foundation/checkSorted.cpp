#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *arr, int size){
    //base case
    if(size == 0 || size == 1) return true;

    // recursion calling
    if(arr[0]>arr[1])          return false;
    else                       return isSorted(arr+1,size-1);
}

int main(){
    int arr[]={2,3,4,5,6,19,7,8,9};


    bool ans = isSorted(arr,sizeof(arr)/sizeof(arr[0]));


    if(ans) cout<<"The array is sorted\n";
    else   cout<<"The array is not sorted ";
}