#include<bits/stdc++.h>
using namespace std;

void shellSort(int A[], int n) {
    int gap,i,j,temp;
    for(gap = n/2; gap>=1; gap/=2) {
        for(i=gap; i<n; i++) {
            temp = A[i];
            j = i - gap;
            while(j>=0 && A[j]>temp) {
                A[j+gap] = A[j];
                j = j - gap;
            }
            A[j+gap] = temp;
        }
    }
}

int main() {
    int arr[] = {3,10,23,14,16,-21,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    shellSort(arr,size);

    for(auto i:arr) cout<<i<<" ";
    return 0;

}