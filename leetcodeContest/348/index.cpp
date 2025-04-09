https://leetcode.com/contest/weekly-contest-438/problems/check-if-digits-are-equal-in-string-after-operations-i/ˀ

class Solution {
    public:
        bool hasSameDigits(string s) {
            int n = s.length();
            while(s.length()!=2){
                n = s.length();
                 string ans="";
                int i=0;
               while(i<n-1) {
                 int num1 = s[i]-'0';
                 int num2 = s[i+1]-'0';
                 ans+= char((num1+num2)%10+'0');
                 i++;    
               }
                s=ans;
            }
            if(s[0]==s[1])return true;
            return false;
        }
    };