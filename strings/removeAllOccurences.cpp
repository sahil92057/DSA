#include "bits/stdc++.h"
#include "iostream"

using namespace std;

string removeAllOccurences(string &full, string pattern ){
    while (full.find(pattern) != string::npos)
    {
        full.erase(full.find(pattern), pattern.length());
    }
 return full;
}


int main(){
    string full="daabcbaabcbc";
    string pattern="abc";
    string ans = removeAllOccurences(full, pattern);
    for(auto it:ans){
        cout<<it;
    }
    return 0;
}