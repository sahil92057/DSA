// https://leetcode.com/problems/find-and-replace-pattern/description/
#include "bits/stdc++.h"
#include "iostream"
using namespace std;


void normalise(string & str){
    unordered_map<char, char> mpp;
    char start='a';
    for(auto it: str){
        if(mpp.find(it)==mpp.end()){
            mpp[it]=start++;
        }
    }
    for(int i =0; i<str.length(); i++){
        str[i]= mpp[str[i]];
    }
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern){
normalise(pattern);
vector<string> ans;
 for (string str : words)
    {
        string temp=str;
        normalise(temp);
        if(temp==pattern) ans.push_back(str);
    }

    return ans;
}

int main()
{
    vector<string> words{"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern="abb";

    vector<string> ans=  findAndReplacePattern(words, pattern);

    for (auto str : ans)
    {
        for (auto str2 : str)
        {
            cout << str2;
        }
        cout << endl;
    }

    return 0;
}