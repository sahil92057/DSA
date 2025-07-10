#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void combSum(vector<int>&v, vector<int>&ans, vector<vector<int>>&output, int target, int i, int n, int &sum){

        if(sum==target){
            for(auto it:ans){
                cout<<it<<" ";
            }
            cout<<endl;
          output.push_back(ans);
        
        return;
    }
    if(i>=n|| target<0) return;

        ans.push_back(v[i]);
        combSum(v, ans, output, target-v[i], i, n ,sum );
        ans.pop_back();
        combSum(v, ans, output, target, i+1, n ,sum );

}

int main (){

    vector<int>v = {2,3,6,7};
    int target = 7;
    vector<int>ans;
    vector<vector<int>>output;
    int n = v.size();
    int sum=0;
    combSum(v, ans, output, target, 0, n, sum);
    return 0;

}