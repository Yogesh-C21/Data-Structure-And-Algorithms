#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for(int i=0; i<n; i++)                    //time complexity of this algorithm will be O(n) since we are traversing array
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
}

int main()
{
    int n,key;   //declare size of array (n) and the key
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cin>>key;
    cout<<linearSearch(arr,n,key);
}