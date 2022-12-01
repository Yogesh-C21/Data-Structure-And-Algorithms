#include<bits/stdc++.h>
using namespace std;

int minJump(int arr[], int n){
    if(n>0){
        if(arr[0]<=0){
            return 0;
        }
        else{
            int idx = 0, jump = 0;
            while(idx<n-1){
                idx = max(idx, idx + arr[idx]);  
                jump++;
            }
            return jump;
        }
    }
    else{
        return 0;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = minJump(arr,n);
    cout<<"The number of Jumps are "<<ans;
}