// #include <bits/stdc++.h>
#include"iostream"
using namespace std;

void func(vector<int > arr, vector<int > &ans, int i, int n, int t){
    if(t==0){
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    for(int j =i; j<n; j++){
        if( arr[j]<=t){
            if(j>i && arr[j]==arr[j-1]) continue;
            ans.push_back(arr[j]);
            func(arr, ans, j+1, n, t-arr[j]);
            ans.pop_back();
        }
        
    }
}

int main() {
	// your code goes here
	
	vector<int > arr ={2, 3, 6, 7, 2, 2, 2, 2};
	int t=7;
	vector<int> ans;
	int n = arr.size();
	func(arr, ans, 0, n, t);

}
