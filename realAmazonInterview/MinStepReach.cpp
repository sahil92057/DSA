// #include <bits/stdc++.h>
#include<iostream>
using namespace std;

#include<iostream>
using namespace std;


bool isSafe(vector<vector<int>> &mat,int i, int j,vector<vector<int>> &vis, int reach, int n){
    if(i>=n|| i<0 || j>=n || j<0 || (vis[i][j]==1)) return false;
    return true;
}

void func(vector<vector<int>> &mat,int &i, int &j,vector<vector<int>> &vis, int &mini, int ans, int n, int &reach){
    if(i==n-1 && j==n-1){
        cout<<"mini "<<mini<<" and ans "<<ans<<endl;
        mini = min(ans, mini);
        return ;
    }
    vector<int>  dirX={0, 1, -1, 0};
    vector<int>  dirY={1, 0, 0, -1};
    for(int k =0; k<4; k++){
        int newx= i+dirX[k];
        int newy= j+dirY[k];
        if(isSafe(mat, newx, newy, vis ,reach, n) ){
            ans+=1;
            vis[newx][newy]=1;
            if(mat[newx][newy]==1 && k>0){
                  vis[newx][newy]=0;
                  k--;
                 func(mat, newx, newy, vis, mini, ans,n,reach);
                  vis[newx][newy]=1;
                  k++;
            }else{
                 vis[newx][newy]=1;
                 func(mat, newx, newy, vis, mini, ans,n,reach);
                 vis[newx][newy]=0;
            }
            vis[newx][newy]=0;
            ans-=1;
        };
    }
}



int main (){
    vector<vector<int>> mat={{0, 0, 0},
                            {0, 1, 0},
                            {0, 0, 1},};
    int n =3;
    vector<vector<int>> vis={{0, 0, 0},
                            {0, 0, 0},
                            {0, 0, 0},};
    int mini =INT_MAX;
    int ans=0;
    int reach=0;
    int i=0, j=0;
    func(mat,i, j, vis, mini, ans, n, reach);
    cout<<"this is the minimum value "<<mini;
    return 0;
}
