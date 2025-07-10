// Online C++ compiler to run C++ program online

// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
#include <iostream>
// #include<bits/stdc++.h>
using namespace std;

int minDeleteSumRec(string s1, string s2, int i, int j) {
    // Base case: if s1 is exhausted, delete all remaining characters of s2
    if (i == s1.size()) {
        int sum = 0;
        while (j < s2.size()) sum += s2[j++];
        return sum;
    }
    // Base case: if s2 is exhausted, delete all remaining characters of s1
    if (j == s2.size()) {
        int sum = 0;
        while (i < s1.size()) sum += s1[i++];
        return sum;
    }

    if (s1[i] == s2[j]) {
        // Characters match, move forward with no deletion
        return minDeleteSumRec(s1, s2, i + 1, j + 1);
    } else {
        // Either delete s1[i] or s2[j]
        int deleteS1 = s1[i] + minDeleteSumRec(s1, s2, i + 1, j);
        int deleteS2 = s2[j] + minDeleteSumRec(s1, s2, i, j + 1);
        return min(deleteS1, deleteS2);
    }
}




int minDeleteSumDp(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
    // Base case: if s1 is exhausted, delete all remaining characters of s2
    
    if(dp[i][j]!=-1) return dp[i][j];
    if (i == s1.size()) {
        int sum = 0;
        while (j < s2.size()) sum += s2[j++];
        return sum;
    }
    // Base case: if s2 is exhausted, delete all remaining characters of s1
    if (j == s2.size()) {
        int sum = 0;
        while (i < s1.size()) sum += s1[i++];
        return sum;
    }

    if (s1[i] == s2[j]) {
        // Characters match, move forward with no deletion
        dp[i][j]= minDeleteSumDp(s1, s2, i + 1, j + 1, dp);
        return dp[i][j];
    } else {
        // Either delete s1[i] or s2[j]
        int deleteS1 = s1[i] + minDeleteSumDp(s1, s2, i + 1, j, dp);
        int deleteS2 = s2[j] + minDeleteSumDp(s1, s2, i, j + 1, dp);
        dp[i][j]= min(deleteS1, deleteS2);
        return  dp[i][j];
    }
}

int main() {
    string s1="sea";
    string s2="eat";
    
    // int ans = minDeleteSumRec(s1, s2, 0, 0);
    // cout<<"this is the count "<<ans;

    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    int ans = minDeleteSumDp(s1, s2, 0, 0, dp);
    cout<<"this is the count "<<ans;
    

    return 0;
}