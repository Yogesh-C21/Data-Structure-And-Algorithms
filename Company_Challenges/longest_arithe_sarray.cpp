#include<iostream>                  /////////kikstart question/////////////
using namespace std;
int main()
{
    int n;                         //length of the array
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int pd = arr[1]-arr[0];   // previous common difference 
    int curr = 2;             // length of the current subarray
    int ans = 2;              // length of the longest subarray
    int j = 2;

    while(j<n)
    {
        if(pd==(arr[j]-arr[j-1]))
        {
            curr++;
        }
        else{
            pd = (arr[j]-arr[j-1]);
            curr = 2;
        }
        ans = max(ans,curr);
        j++;
    }
    cout<<ans;
}