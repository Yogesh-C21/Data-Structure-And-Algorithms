#include<bits/stdc++.h>
#include "node.h"
using namespace std;

int hashK(int key) {
    return key%10;
}

void create(struct Node* HT[], int key) {
    int index = hashK(key);
    sortedInsert(&HT[index], key);
}

int main() {
    struct Node* hashTable[10];
    for(int i=0; i<10; i++) {
        hashTable[i] = NULL;
    }
    create(hashTable, 12);
    create(hashTable, 42);
    create(hashTable, 25);
    create(hashTable, 65);
    create(hashTable, 11);

    struct Node* temp = search(hashTable[hashK(12)], 12);
    int deletedValue = deletion(hashTable[hashK(65)], 65);
    cout<<temp->data<<" is the searched value\n";
    cout<<deletedValue<<" is the deleted value\n";
}
