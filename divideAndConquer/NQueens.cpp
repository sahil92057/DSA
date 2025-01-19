#include "bits/stdc++.h"
#include "iostream"
using namespace std;
bool isSafe(unordered_map<int, bool> &ud, unordered_map<int, bool> &ld, unordered_map<int, bool> &rc
, int row, int col){
   if(ud[row-col] == true|| ld[row+col] == true|| rc[row] == true ) return false;
   return true;
}
void  saveAns(vector<vector<char>> &b, vector<string> & ans, int n){
    vector<string> vecString;

    for(auto it:b){
        string temp;
        for(auto it2:it){
            temp+=it2;
        }
        ans.push_back(temp);
    }
}
void solve(int n, int col, vector<vector<char>> &b, vector<string> & ans, 
  unordered_map<int, bool> &ud, unordered_map<int, bool> &ld, unordered_map<int, bool> &rc){
    if(col>=n){
        saveAns(b, ans, n);
    }
    for(int row=0; row<n; row++){
        if(isSafe(ud, ld, rc, row, col)){
            ud[row-col] = true;
            ld[row+col] = true;
            rc[row] = true;
            b[row][col]='Q';
            solve(n, col+1, b, ans,ud, ld, rc );
            ud[row-col] = false;
            ld[row+col] = false;
            rc[row] = false;
            b[row][col]='.';
        }
    }
  }


int main(){
   int n=4, col=0;
   vector<vector<char>> b(n, vector<char>(n, '.'));
   vector<string> ans;
   unordered_map<int, bool> ud;
   unordered_map<int, bool> ld;
   unordered_map<int, bool> rc;

   solve(n, col, b, ans, ud, ld, rc);


   for(auto it:ans){
    for(auto it2:it){
        cout<<" "<<it2;
    }
    cout<<endl;
   }

    return 0;
}
