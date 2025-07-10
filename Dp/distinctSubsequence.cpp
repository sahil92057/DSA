#include"iostream"
using namespace std;


int distinctSubseqenceRec(string s1, string s2, int i, int j,  vector<vector<int>>&dp ){
    if(j==s2.size()-1 && s1[i]==s2[j]) return 1;
    if(i>=s1.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int lh =0, rh=0;
    if(s1[i]==s2[j]){
         lh= distinctSubseqenceRec(s1, s2, i+1, j+1, dp);
    }
    rh= distinctSubseqenceRec(s1, s2, i+1, j, dp);
     dp[i][j]= lh+rh;
     return lh+rh;
}


int main(){
    string s1="rabbbit";
    string s2="rabbit";
    
    // int ans = distinctSubseqenceRec(s1, s2, 0, 0);
    // cout<<"this is the ans "<< ans;


    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
    int ansdp = distinctSubseqenceRec(s1, s2, 0, 0, dp);
    cout<<"this is the ans "<< ansdp;

    return 0;
}