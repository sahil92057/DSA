#include "iostream"
#include "stack"
using namespace std;


bool validStack(stack<char> &st, string &s){
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(st.empty()) return false; 
            char top= st.top();
            st.pop();
            if((top=='(' &&  s[i]!=')') ||
             (top=='{' &&  s[i]!='}') ||
              (top=='[' &&   s[i]!=']'))
               return false;
        }
    }

    return st.empty();
}


int main(){
    string str="{{{}}}}";
    stack<char> st;
    bool ans = validStack(st, str);
    cout<<"this is the ans ==>> "<<ans;
    return 0;
}