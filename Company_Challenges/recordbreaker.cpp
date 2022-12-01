#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;   //no of days stored in an array
    cin>>n;
    int arr[n+1];
    arr[n] = INT_MIN;
    int mx = INT_MIN, ans = 0;    // maximum number of visitors and count of record breaking days respectively
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(n==1 && arr[0]>0){
        cout<<"The number of record breaking day is 1";
        return 0;
    }
    for(int i=0; i<n; i++){
        if(arr[i]>mx && arr[i]>arr[i+1]){               
            ans++;
        }
        mx = max(mx, arr[i]);
    }
    cout<<"The number of record breaking days are "<<ans;
    return 0;
}