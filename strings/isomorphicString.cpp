#include "bits/stdc++.h"
#include "iostream"
using namespace std;
 bool isIsomorphic(string s, string t) {
    unordered_map<char, char> mpp;
    for(int i=0;i<s.length();i++){
        if(mpp.find(s[i])==mpp.end()){
            mpp[s[i]]=t[i];
        }else{
            if(mpp[s[i]]!=t[i]){
                return false;
            }
        }
    }
        return true;
    }

int main (){
    string s="addf";
    string t="ghhe";
 bool ans = false;
    if(s.length()==t.length()){
        ans = isIsomorphic(s, t);
    }

    cout<<ans;
    return 0;
}