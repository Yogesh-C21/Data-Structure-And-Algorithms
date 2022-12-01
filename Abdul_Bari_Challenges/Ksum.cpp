#include<bits/stdc++.h>
using namespace std;

void KsumSortedArray(int arr[], int n, int sum) {
    int i = 0;
    int j = n - 1;
    while(i<j) {
        if((arr[i]+arr[j])>sum) j--;
        else if((arr[i]+arr[j])<sum) i++;
        else {
            cout<<"Sum of "<<arr[i]<<" and "<<arr[j]<<" is "<<arr[i]+arr[j]<<endl;
            i++;
            j--;
        }
    }
}

void KsumUnsortedArray(int arr[], int n, int sum) {

    /* Method 1 Iterative Approach */
    /* for(int i =0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i]+arr[j]==sum) {
                cout<<"Sum of "<<arr[i]<<" and "<<arr[j]<<" is "<<arr[i]+arr[j]<<endl;
            }
        }
    } */

    /* Method 2 Hashing*/

    /* negative indices will give garbage value since do not exist inside the array */

    int hashArray[100] = {false};
    for(int i =0; i<n; i++) {
        if(hashArray[sum-arr[i]] == true) cout<<"10 is pair of "<<arr[i]<<" and "<<sum-arr[i]<<endl;
        hashArray[arr[i]] = true;
    }
}

int main() {
    int sortedArray[] = {1,3,4,5,6,8,9,10,12,14};
    int unsortedArray[] = {6,3,8,10,16,7,5,2,9,14,-4};
    int sortedLength = sizeof(sortedArray)/sizeof(sortedArray[0]);
    int unsortedLength = sizeof(unsortedArray)/sizeof(unsortedArray[0]);
    // KsumSortedArray(sortedArray, sortedLength, 10);
    KsumUnsortedArray(unsortedArray, unsortedLength, 10);
}