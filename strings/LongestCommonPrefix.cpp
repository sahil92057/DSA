// https://leetcode.com/problems/longest-common-prefix/description/
#include "bits/stdc++.h"
#include "iostream"

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans =strs[0];
    for(int i=0; i<strs.size(); i++){
        string cmn;
        for(int j=0; j<strs[i].size(); j++){
            if(ans[j]==strs[i][j]){
                cmn+=ans[j];
            }
        }
        ans=cmn;
    }
    return ans;
}

int main()
{

    vector<string> str{"flower", "flow", "flight"};
    string ans = longestCommonPrefix(str);
    for(auto it:ans) cout<<it;
    return 0;
}