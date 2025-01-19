#include "bits/stdc++.h"
#include "iostream"
using namespace std;


string removeDupAdj(string s, int n){
   string temp;
   for(auto it:s){
    if(temp.length()==0)temp+=it;
    else{
        if(temp[temp.length()-1]==it) temp.pop_back();
        else temp+=it;
    }
   }
   return temp;
}

int main (){

    string s="abbaca";
    int n = s.length();
    string ans= removeDupAdj(s, n);
    for(auto it: ans){
      cout<<it;
    }
    return 0;
}