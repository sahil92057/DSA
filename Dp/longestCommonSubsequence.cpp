#include"iostream"
using namespace std;

int findSeq(string t1, string t2, int n, int m, int i, int j, vector<vector<int>>&dp){
    if(i>=m || j>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(t1[i]==t2[j]){
        dp[i][j]=1+findSeq(t1, t2,n, m, i+1, j+1, dp);
    }else{
        dp[i][j]= max(findSeq(t1, t2,n, m, i+1, j, dp), findSeq(t1, t2,n, m, i, j+1, dp));
    }
   
    return dp[i][j];
}
int main (){
    string t1="abcde";
    string t2="ace";

    int m = t1.size();
    int n = t2.size();
    vector<vector<int>>dp(n+10, vector<int>(m+10, -1));
    int ans = findSeq(t1, t2, n, m, 0, 0, dp);
    cout<<ans;
    return 0;
}