#include "bits/stdc++.h"
#include <iostream>
using namespace std;

bool isSafe(vector<vector<int>> &m,int n, int newx, int newy, vector<vector<int>> &vis){
    if(newx < 0 || newx >= n || newy < 0 || newy >= n) return false;

    if(vis[newx][newy]==true) return false;
    if(m[newx][newy]==0) return false;
    return true;

}

void solve(vector<vector<int>> &m, int n, int srcx, int srcy, vector<string> &ans, vector<vector<int>> &vis, string &track ){
    if(srcx ==n-1 && srcy==n-1){
        ans.push_back(track);
        return;
    }
    
    int dirx[] = {-1, 1, 0, 0};
    int diry[]=  {0, 0, 1, -1};
    char dirC[]={'U', 'D', 'R', 'L'};
    for(int i =0; i<4; i++){
       int newx = srcx + dirx[i];
int newy = srcy + diry[i];


        if(isSafe(m ,n, newx, newy, vis)){
            vis[newx][newy]=true;
             track+=dirC[i];
            solve(m, n, newx, newy, ans, vis, track);
            vis[newx][newy]=false;
            track.pop_back();
        }
    }
}


int main (){
    int n =4;
      
   vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    if(m[0][0]!=0){
      
      int srcx =0, srcy=0;
      vector<string> ans;
      string track = "";
      vector<vector<int>> vis(n, vector<int>(n, false));
      vis[srcx][srcy] = true; 
      solve(m, n, srcx, srcy, ans, vis, track);
      for(auto it:ans){
         for(auto it2:it){
            cout<<it2;
         }
         cout<<endl;
      }
    } 
    return 0;
}