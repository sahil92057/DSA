// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> mat, int i, int j){
    int n = mat.size();
    if(i>-1 && j>-1 && i<n && j<n && mat[i][j]!=0)return true;
    return false;
}
void func(vector<vector<int>> mat, int i, int j, vector<vector<char>>&output,vector<char>& ans, vector<vector<int>> &vis, int n){
    if(i==n-1 && j==n-1){
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
        output.push_back(ans);
        return;
    }
    vector<int> dirx = {-1, 1, 0, 0};
    vector<int> diry = {0, 0, -1, 1};
    vector<int> dir = {'U', 'D', 'L', 'R'};
    for(int k =0; k<4; k++){
        int newi= dirx[k]+i;
        int newj= diry[k]+j;
        if(isSafe(mat, newi, newj) && !vis[newi][newj]){
            vis[newi][newj]=1;
            ans.push_back(dir[k]);
            func(mat, newi, newj, output, ans, vis, n);
            vis[newi][newj]=0;
            ans.pop_back();
        }
    }
}

int main() {
    int n=4;
    vector<std::vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<vector<int>> vis(n, (vector<int>(n, 0)));
    vector<vector<char>> output;
    vector<char> ans;
    func(mat, 0, 0, output, ans, vis, n);

    return 0;
}