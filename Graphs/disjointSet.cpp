#include<bits/stdc++.h>
using namespace std;

vector<int> parent(4,-1);

int find(int v) {
    if(parent[v]==-1) return v;
    return find(parent[v]);
}

void makeUnion(int u, int v) {
    int from = find(u);
    int to = find(v);
    parent[from] = to;
    cout<<from<<" and "<<to<<" are united\n";
}

bool isCyclic(vector<pair<int,int>> &edgeList) {
    int from,to;
    for(auto x:edgeList) {
        from = find(x.first);
        to = find(x.second);
        if(from == to) return true;
        makeUnion(from, to);
    }
    return false;
}


int main() {
    int E;  //edges
    int V; //vertices
    /* cin>>E>>V;
    parent.resize(V,-1); */
    vector<pair<int,int>> edgeList{{0,1},{0,3},{2,3},{1,2}};
   /*  for(int i=0; i<E-1; i++) {
        int from,to;
        cin>>from>>to;
        edgeList.push_back({from,to});
    } */    

    // edgeList Created 

    string str = isCyclic(edgeList) ? "Cycle Exist" : "Cycle do not exist";

    cout<<str;
    
}