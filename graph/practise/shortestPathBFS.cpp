#include"iostream"
// #include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v,int w,  int dir,unordered_map<int, vector<pair<int, int>>>&adjList){
    if(dir){
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }else{
        adjList[v].push_back({u, w});
    }
}



void topoSort(int src, unordered_map<int, vector<pair<int, int>>> &adjList, int dest){
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
            if(!vis[nbr.first]){
                vis[nbr.first]=true;
                q.push(nbr.first);
                parent[nbr.first]=frontNode;
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
    unordered_map<int, vector<pair<int, int>>> adjList;
     int n =5;
    stack<int> st;
    // addEdge(1, 2,  1, adjList);
    // addEdge(2, 3,  1, adjList);
    // addEdge(3, 4,  1, adjList);
    // addEdge(4, 5,  1, adjList);
    // addEdge(5, 6,  1, adjList);
addEdge(0,1,5,1, adjList);

addEdge(0,2,13,1, adjList);

addEdge(0,4,3,1, adjList);

addEdge(1,2,7,1, adjList);

addEdge(1,4,1,1, adjList);

addEdge(4,3,6,1, adjList);

addEdge(3,2,2,1, adjList);
    // topoSortDFS(1, vis, adjList, st);
topoSort(1, adjList, 5);
    return 0;
}