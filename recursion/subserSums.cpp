// #include <bits/stdc++.h>
#include "iostream"
using namespace std;

void findSubsetSums(vector<int>arr, vector<int >&ans, int i, int sum, int n){
    if(i>=n){
        ans.push_back(sum);
        return;
    }
    findSubsetSums(arr, ans, i+1, sum+arr[i], n);
    findSubsetSums(arr, ans, i+1, sum, n);
    
}

int main() {
	// your code goes here
	vector<int>arr = {5,2,1};
	int n = arr.size();
	vector<int >ans;
	findSubsetSums(arr, ans, 0,0, n);
	for(auto it: ans){
	    cout<<" "<<it;
	}
	
}
