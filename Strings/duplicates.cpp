#include<bits/stdc++.h>
using namespace std;

int main() {
    char ch[] = "findingtheduplicate";
    int hashArray[26] = {0};
    for(int i=0; ch[i]!='\0'; i++) {
        hashArray[ch[i]-97]++;
        if(hashArray[ch[i]-97]>1) {
            char temp = ch[i];
            cout<<temp<<" has already appeared before\n";
        }
    }
    for(auto x: hashArray) cout<<x;
}