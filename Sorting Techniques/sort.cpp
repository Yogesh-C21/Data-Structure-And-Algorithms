#include<iostream>
#include<climits>
using namespace std;

int sort(int arr[], int n)
{
    int mini= INT_MAX;
    for(int i=0; i<n; i++)
    {
        mini = min(mini,arr[i])
    }
}
int main()
{
    int n;
    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,n);

}