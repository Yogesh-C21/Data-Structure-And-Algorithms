#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {5,6,7,8,9,10,12,13,15,18,25};
    // indices   0,1,2,3,4, 5, 6, 7, 8, 9, 10, 11 
    int length = sizeof(arr)/sizeof(arr[0]);
    /* int diff = arr[0];
    for(int i=0; i<length; i++) {
        int addedValue = 1;
        while(((arr[i] - i)-diff)!=0) {
            cout<<arr[i-1]+ addedValue <<" is the missing number from the sorted array"<<endl;
            addedValue++;
            diff++;
        }  
    } */

    /* Method 2 (optimised method 1) */
     
    /* for(int i=0; i<length; i++) {
        while(diff < (arr[i] - i)) {
            cout<< i + diff <<" is the missing number from the sorted array"<<endl;
            diff++;
        }  
    } */

    /* Method 3 (Hashing/Hashtable) */

    int hashLength = arr[length-1] + 1;
    int hashArray[hashLength] = {false};
    for(int i =0; i<length; i++) hashArray[arr[i]] = true; // used hashtable
    for(int i = arr[0]; i<hashLength; i++) {
        if(hashArray[i]!=1) {
            cout<<i<<" is the missing element in the array"<<endl;
        }
    }
}