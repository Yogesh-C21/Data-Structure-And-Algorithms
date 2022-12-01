#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    while(n>0)
    { 
        for(int k=0; k<n-1; k++)
        {
            if(arr[k]>arr[k+1])
        {
            int temp;
            temp = arr[k];
            arr[k]=arr[k+1];
            arr[k+1]=temp;
        }
        cout<<arr[k]<<" ";
        }
        cout<<n<<" ";
        n--;  
    }
     for(int i=0; i<n; i++)
    {
        cout<<arr[i];
    }

}