#include "bits/stdc++.h"
#include "iostream"
using namespace std;

bool checkPalindrome(string s, int i, int j ){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        else{i++;j--; }
    }
    return true;
}

bool validPalindrome2(string &s)
{
    int n = s.length();
    int i=0, j=n-1;
    while(i<=j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else{
            bool ansOne = checkPalindrome(s, i+1, j);
            bool ansTwo = checkPalindrome(s, i, j-1);
            return ansOne || ansTwo;
        }
    }

    return true;
}

int main()
{
    string s="rabbcar";
    bool ans = validPalindrome2(s);
    cout << "this is the answer man " << ans;
    return 0;
}