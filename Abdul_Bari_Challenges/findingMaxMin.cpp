#include<bits/stdc++.h>
using namespace std;

int main() {
    int array[] = {2,5,4,-1,4,55,23,-873,23,90,182};
    int length = sizeof(array)/sizeof(array[0]);
    int min = INT_MAX;
    int max = INT_MIN;

    for(int i=0; i<length; i++) {
        if(array[i]>max) max = array[i];
        if(array[i]<min) min = array[i];
    }
    cout<<"Max is "<<max<<" and min is "<<min;

}