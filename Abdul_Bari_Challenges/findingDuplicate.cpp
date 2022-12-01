#include<bits/stdc++.h>
using namespace std;

int main() {
    int array[] = {3,4,5,5,6,7,8,9,9,9,9,9,9,9,9,10,12,13,13};
    int length = sizeof(array)/sizeof(array[0]);

    int unsortedArray[] = {8,3,6,4,6,5,6,8,2,7,53,33,44,53};
    int n = sizeof(unsortedArray) / sizeof(unsortedArray[0]);

    /* duplicates in an unsorted array */

    for(int i =0; i <n-1; i++) {
        int count = 1;
        if(unsortedArray[i]!=INT_MIN) {
            for (int j = i+1; j<n; j++) {
            if(unsortedArray[j] == unsortedArray[i]) {
                unsortedArray[j] = INT_MIN;
                count++;
            }
        }
        }
        if(count>1) cout<<unsortedArray[i]<<endl;
    }

    /* Method 1 (Using iterative approach) */
    /* int lastDuplicate = 0;
    for(int i = 1; i<length; i++) {
        if(array[i-1]==array[i] && array[i]!=lastDuplicate){
            cout<<array[i]<<" is the duplicate element\n";
            lastDuplicate = array[i];
        }
    } */
    /* Counting no of times elements are appearing */
    /* int count = 0;
    for(int i=0; i<length; i++) {
        if(array[i-1]==array[i]) {
            count = i;
            while(array[count] == array[i-1]) count++;
            cout<<array[i-1]<<count;
            i = count - 1;
        }
    } */

    


    /* Using Hashing Technique */


    /* int hashLength = array[length-1] + 1;
    int hashArray[hashLength] = {0};
    for(int i = 0; i<length; i++) hashArray[array[i]]++;
    for(int i = array[0]; i<hashLength; i++) {
        if(hashArray[i]>1) {
            cout<<i<<" is "<<hashArray[i]<<" times in the array\n";
        }
    } */
}