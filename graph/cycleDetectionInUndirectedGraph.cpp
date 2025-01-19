// #include "bits/stdc++.h"
// #include "iostream"
// using namespace std;



    // void addEdge(int u, int v,  int dir,  unordered_map<int, vector<int>>&adjList){
    //     if(dir){
    //         adjList[u].push_back (v);
    //         adjList[v].push_back (u);
    //     }else{
    //         adjList[v].push_back (u);

    //     }

// };
// bool cycleDetectionInUndirectedGraph(int src, unordered_map<int, bool> &vis, unordered_map<int, vector<int>> &adjList,
//                                      unordered_map<int, int> &parent)
// {
//     queue<int> q;
//     q.push(src);
//     vis[src] = true;
//     while (!q.empty())
//     {
//         int frontNode = q.front();
//         q.pop();
//         if (!vis[frontNode])
//         {
//             for (auto nbr : adjList[frontNode])
//             {
//                 for (auto nbrEle : nbr.second)
//                 {
//                     if (!vis[nbrEle])
//                     {
//                         q.push(nbrEle);
//                         vis[nbrEle] = true;
//                         parent[frontNode]= nbrEle;
//                     }
//                     else if (vis[nbrEle] == true && nbrEle != parent[frontNode])
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//     }

//     return false;
// }

// int main()
// {
//     unordered_map<int, bool> vis;
//     unordered_map<int, vector<int>> adjList;
//      int n =5;
//     // addEdge(1, 2,  1, adjList);
//     // addEdge(2, 3,  1, adjList);
//     // addEdge(3, 4,  1, adjList);
//     // addEdge(4, 5,  1, adjList);
//     // addEdge(5, 6,  1, adjList);

//     addEdge(1, 2, 1, adjList);
//     addEdge(2, 3, 1, adjList);
//     addEdge(3, 4, 1, adjList);
//     addEdge(4, 5, 1, adjList);
//     addEdge(5, 1, 1, adjList); 
//     unordered_map<int, int> parent;
//     bool ans= false;
//     for (auto nbr : adjList)
//     {
//         if(!vis[nbr.first]){ 
//             ans = cycleDetectionInUndirectedGraph(nbr.first, vis, adjList, parent);
//             if(ans==true)   break;
//         }
//     }

//     cout<<"here is the answer "<<ans;

//     return 0;
// }