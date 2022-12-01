#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    int name;
    string s;
    bool gender;

};

int main()
{
    student s[3];
    for(int i=0; i<3; i++){
        cin>>s[i].name;
        cin>>s[i].s;
        cin>>s[i].gender;
    }
    for(int i=0; i<3; i++){
        cout<<s[i].name;
        cout<<s[i].s;
        cout<<s[i].gender;
    }
}
