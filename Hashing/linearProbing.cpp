#include<bits/stdc++.h>
#define size 10
using namespace std;

int hashK(int key) {
    return key%size;
}

int probe(int H[], int key) {
    int index = hashK(key);
    int i=0;
    while(H[(index + i)%size] != 0) {
        i++;
    }
    return (index+i)%size;
}

void insert(int H[], int key) {
    int index = hashK(key);
    if(H[index] != 0) {
        index = probe(H,key);
    }
    H[index] = key;
}

int search(int H[], int key) {
    int index = hashK(key);
    int i = 0;
    /* since deletion is not preferred in linear probing so using this method */
    while(H[(index + i)%size] != 0) {
        if(H[(index + i)%size] == key) return (index + i)%size;
        i++;
    }
    return -1;
}

int main() {
    cout<<"----------------------------------------------OUTPUT AREA-------------------------------------------------------\n\n\n\n";
    int H[10] = {0};
    insert(H,12);
    insert(H,25);
    insert(H,35);
    insert(H,26);
    int elementIndex = search(H,26);
    cout<<"Key found at index "<<elementIndex<<"\n";
    cout<<"\n\n\n----------------------------------------------OUTPUT AREA-------------------------------------------------------";
}
