#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, mindx = INT_MAX;             //size of the array and variable that store  the minimum value of all the indices.
    const int N = 1e6+2;
    cin>>n;                               
    int arr[n], idx[N];                  // original array and the indices array.

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<N; i++){
        idx[i]=-1;
    }
    for(int i=0; i<n; i++){
        if(idx[arr[i]]!=-1){
            mindx = min(mindx,idx[arr[i]]);
        }
        else{
            idx[arr[i]]=i;
        }
    }

    if(mindx==INT_MAX){
        cout<<"Index not found ";
    }



}