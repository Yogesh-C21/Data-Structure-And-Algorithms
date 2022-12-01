#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int start = 0 , end = n;  
    while(start<=end)
    {   
        int mid = (start+end)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            end = mid - 1;
        }
        else 
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n,key;     //size of array (n) and the key that we have to find
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cin>>key;
    cout<<binarySearch(arr,n,key);
    return 0;
}