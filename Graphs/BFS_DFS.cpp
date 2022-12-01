#include<bits/stdc++.h>
#include "queue.h"
using namespace std;

void BFS(int G[][6], int start, int n) {
    int visited[n] = {0}, u,v;
    cout<<start<<" ";
    visited[start] = 1;
    enqueue(start);
    while(!isEmpty()) {
        u = dequeue();
        for(v=1;v<=n;v++) {
            if(G[u][v]==1 && visited[v]==0) {
                cout<<v<<" ";
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

void DFS(int G[][6], int start, int n) {
    static int visited[6] = {0};
    int v;
    if(visited[start]==0) {
        cout<<start<<" ";
        visited[start] = 1;
            for(v=1; v<n; v++) {
            if(G[start][v] == 1 && visited[v]==0) DFS(G,v,n);
        }
    }
}

int main() {

    int arr[6][6] = {{0,0,0,0,0,0},
                    {0,0,1,1,1,0},
                    {0,1,0,1,0,0},
                    {0,1,1,0,1,1},
                    {0,1,0,1,0,0},
                    {0,0,0,1,1,0}};

    DFS(arr,1,6);

    return 0;
}