#include "bits/stdc++.h"
#include "iostream"
using namespace std;
/// note toposort using BFS only be done in ADG (Acylic Directed graph)

void addEdge(int u, int v,  int dir,unordered_map<int, vector<int>>&adjList){
    if(dir){
        adjList[u].push_back (v);
        adjList[v].push_back (u);
    }else{
        adjList[v].push_back (u);
    }
}


void topoSortBFS(int n,  unordered_map<int, vector<int>> &adjList, vector<int> &ans){
    unordered_map<int, int> inEdge;
    queue<int> q;
    for(int src =0; src<n; src++){
        for(auto it : adjList[src]){
            inEdge[it]++;
        }
    }
    for(int i =0; i<n; i++){
        if(inEdge[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto it:adjList[frontNode]){
           inEdge[it]--;
           if(inEdge[it]==0) q.push(it);
        }
    }

}


int main (){
    int n =5;
    unordered_map<int, vector<int>> adjList;
    addEdge(1, 2,  1, adjList);
    addEdge(2, 3,  1, adjList);
    addEdge(3, 4,  1, adjList);
    addEdge(4, 5,  1, adjList);
    addEdge(5, 6,  1, adjList);
    vector<int> ans;
    topoSortBFS(n, adjList,ans);
    for(auto it:ans){
        cout<<" "<<it; 
    }

    return 0;
}