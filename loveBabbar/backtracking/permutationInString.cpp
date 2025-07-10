#include<bits/stdc++.h>
using namespace std;
void permute(int i, vector<vector<string>> &output, vector<string> &ans, int n, vector<string>  &str){
    if(i>=n){
        output.push_back(str);
        return;
    }
    for(int j =i; j<n;j++){
        swap(str[i], str[j]);
        permute(i+1, output, ans, n, str);
        swap(str[i], str[j]);
    }
}



int main(){
vector<string> str = {"a", "b", "c"};
    int n = str.size();
    vector<string> ans;
    vector<vector<string>> output;
    permute(0, output, ans, n, str);
    for(auto it:output){
        for(auto it2:it){
        cout<<it2;
        }
        cout<<endl;
    }
    return 0;
}