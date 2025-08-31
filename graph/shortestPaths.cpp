#include "iostream"
#include"set"
using namespace std;
void addEdge( unordered_map<int, vector<pair<int, int>>>& adjList, int u, int v , int w, int dir){
    if(dir){
        adjList[u].push_back({v, w});
    }else{
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
}

vector<int> dijkstra(unordered_map<int, vector<pair<int, int>>> &adjList, int src, int n) {
    set<pair<int, int>> st; // {distance, node}
    vector<int> dest(n, INT_MAX);
    dest[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        auto topPair = *st.begin();
        st.erase(st.begin());

        int node = topPair.second;
        int dist = topPair.first;

        for (auto nbr : adjList[node]) {
            int nbrNode = nbr.first;
            int edgeWeight = nbr.second;

            if (dist + edgeWeight < dest[nbrNode]) {
                // If nbrNode was previously in set, remove it
                if (dest[nbrNode] != INT_MAX) {
                    st.erase({dest[nbrNode], nbrNode});
                }

                // Update with new smaller distance
                dest[nbrNode] = dist + edgeWeight;
                st.insert({dest[nbrNode], nbrNode});
            }
        }
    }

    return dest;
}

void ShortestBFS(unordered_map<int, vector<pair<int, int>>> &adjList, int src, unordered_map<int, bool> &vis, unordered_map<int, int> &parent, int dest){
    queue<int> q;
    q.push(src);
    parent[src]=-1;
    vis[src]=true;
    while(!q.empty()){
        int FN= q.front();
        q.pop();
        for(auto nbr:adjList[FN]){
            if(!vis[nbr.first]){
                q.push(nbr.first);
                vis[nbr.first]=true;
            }
        }
    }
    
    int node =dest;
    vector<int> ans;
    while(node!=-1){
        ans.push_back(node);
        node = parent[node];
    }
    sort(ans.begin(), ans.end());
    for(auto it:ans){
        cout<<it;
    }
    
    
}


int main() {
    unordered_map<int, vector<pair<int, int>>> adjList;
    unordered_map<int, bool> vis;
    unordered_map<int, int> parent;
    addEdge(adjList, 0, 5,9,1);
    addEdge(adjList, 0, 3,6,1);
    addEdge(adjList, 5, 4,2,1);
    addEdge(adjList, 4, 3,11,1);
    addEdge(adjList, 5, 1, 14,1);
    addEdge(adjList, 4, 1, 9,1);
    addEdge(adjList, 4, 2, 10,1);
    addEdge(adjList, 3, 2, 15,1);
    addEdge(adjList, 2, 1, 7,1);
    int n = 6;
    int dest=3;
    // for(int i=0; i<=n; i++){
    //     if(!vis[i]){
    //         ShortestBFS(adjList, i, vis,parent, dest);
    //     }
    // }


    vector<int> ans=dijkstra(adjList, 0, n);
    for(auto it:ans){
        cout<<" "<< it;
    }

    return 0;


}
