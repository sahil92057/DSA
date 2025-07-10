#include"iostream"
// #include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v,  int dir,unordered_map<int, vector<int>>&adjList){
    if(dir){
        adjList[u].push_back (v);
        adjList[v].push_back (u);
    }else{
        adjList[v].push_back (u);
    }
}



void topoSort(int src, unordered_map<int, vector<int>> &adjList, int dest){
    queue<int> q;
    unordered_map<int , int >parent;
    unordered_map<int , bool >vis;
    q.push(src);
    parent[src]=-1;
    while(!q.empty()){
        int frontNode= q.front();
        q.pop();
        vis[src]=true;
        for(auto nbr:adjList[frontNode]){
            if(!vis[nbr]){
                vis[nbr]=true;
                q.push(nbr);
                parent[nbr]=frontNode;
            }
        }
    }


    vector<int> source;
    int node=dest;
    while(node!=-1){
        source.push_back(node);
        node = parent[node];
    }

    sort(source.begin(), source.end());
    for(auto it:source){
        cout<<it<<" ";
    }



}


int main (){
    int src;
    unordered_map<int, bool> vis;
    unordered_map<int, vector<int>> adjList;
     int n =5;
    stack<int> st;
    addEdge(1, 2,  1, adjList);
    addEdge(2, 3,  1, adjList);
    addEdge(3, 4,  1, adjList);
    addEdge(4, 5,  1, adjList);
    addEdge(5, 6,  1, adjList);
    // topoSortDFS(1, vis, adjList, st);
topoSort(1, adjList, 5);
    return 0;
}