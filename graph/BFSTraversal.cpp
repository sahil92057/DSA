#include "bits/stdc++.h"
#include<iostream>
using namespace std;
void addEdge(int u, int v, int edge, int dir, unordered_map<int, vector<pair<int, int>>> &adjList){
    if(dir){
        adjList[u].push_back (make_pair(v, edge));
        adjList[v].push_back (make_pair(u, edge));
    }else{
        adjList[v].push_back (make_pair(u, edge));

    }
};

void BFSTraversal(int src, unordered_map<int, vector<pair<int, int> >> &adjList, unordered_map<int, bool> vis){
    queue<int> q;
    q.push(src);
    vis[src]=true;
   while(!q.empty()){
    int frontNode = q.front();
    q.pop();
    cout<<" "<<frontNode;
    for(auto nbr :adjList[frontNode]){
        if(!vis[nbr.first]){
            q.push(nbr.first);
            vis[nbr.first]=true;
        }
    }
   }



    
}


bool cycleDetectionInUndirectedgraph(){
    
}

int main(){
    unordered_map<int, vector<pair<int, int> >> adjList;
    int n =5;
    addEdge(1, 2, 5, 1, adjList);
    addEdge(2, 3, 5, 1, adjList);
    addEdge(3, 4, 5, 1, adjList);
    addEdge(4, 5, 5, 1, adjList);
    addEdge(5, 6, 5, 1, adjList);
    unordered_map<int, bool> vis;
    BFSTraversal(1, adjList,vis);
   
    return 0;  
}