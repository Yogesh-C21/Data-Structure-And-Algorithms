#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> vt;
    vt.push_back(1);
    vt.push_back(33);
    vt.push_back(43);
    for(int i=0; i<sizeof(vt); i++)
    {
        cout<<vt[i]<<"\t";
    }
    return 0;
}