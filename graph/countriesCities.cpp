#include <bits/stdc++.h">
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &adj, set<pair<int,int>> &edges, int &reversals, vector<bool> &visited) {
    visited[node] = true;
    for (int nei : adj[node]) {
        if (nei == parent) continue;
        if (!visited[nei]) {
            if (edges.find({node, nei}) == edges.end())
                reversals++;
            dfs(nei, node, adj, edges, reversals, visited);
        }
    }
}

vector<int> countReverseEdges(int g_nodes, int g_edges, const vector<int> &g_from, const vector<int> &g_to) {
    vector<vector<int>> adj(g_nodes+1);
    set<pair<int,int>> edges; 
    for (int i = 0; i < g_edges; ++i) {
        int u = g_from[i], v = g_to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.insert({u, v});
    }

    vector<int> result;
    for (int root = 1; root <= g_nodes; ++root) {
        vector<bool> visited(g_nodes+1, false);
        int count = 0;
        dfs(root, 0, adj, edges, count, visited);
        result.push_back(count);
    }
    return result;
}

int main() {
    int g_nodes = 4, g_edges = 3;
    vector<int> g_from = {1, 2, 3};
    vector<int> g_to = {4, 4, 4};
    vector<int> res = countReverseEdges(g_nodes, g_edges, g_from, g_to);
    for (int x : res) cout << x << " ";
    cout << endl; 
    return 0;
}
