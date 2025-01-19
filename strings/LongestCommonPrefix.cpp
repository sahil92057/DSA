// https://leetcode.com/problems/longest-common-prefix/description/
#include "bits/stdc++.h"
#include "iostream"

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans;
    int k =0, i=0, j=0;
    while(strs[i+k][j]==strs[i+k+1][j] && strs[i+k][j]==strs[i+k+2][j]){
        ans+=strs[i+k][j];
        i++;j++;
    }
  
    return ans;
}

int main()
{

    vector<string> str{"flower", "flow", "flight"};
    string ans=longestCommonPrefix(str);
    cout<<ans;
    return 0;
}