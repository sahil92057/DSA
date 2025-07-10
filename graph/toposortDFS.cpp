// #include "bits/stdc++.h"
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



void topoSortDFS(int src,unordered_map<int, bool> &vis, unordered_map<int,
 vector<int>> &adjList, stack<int> &st ){

    vis[src]=true;
        for(auto it:adjList[src]){
            if(!vis[it]){
                st.push(it);
                vis[it]=true;
                topoSortDFS(it, vis, adjList, st);
                cout<<" "<<st.top();
                st.pop();
            }
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
    topoSortDFS(1, vis, adjList, st);

    return 0;
}