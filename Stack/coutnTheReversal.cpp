#include "iostream"
#include "stack"
using namespace std;

int countTheReversal(stack<char> st, string & str){
    int cnt=0;
    for(char ch:str){
       if(ch=='{') st.push(ch);
       else{
        if(!st.empty() && st.top()=='{') st.pop();
        else st.push(ch);
       }
    }

    while(!st.empty()){
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();
        if(a==b) cnt+=2;else cnt+=1;
    }
    return cnt;
}


int main (){
    string str="}{{}}{{{";
    stack<char> st;
    cout<<"this is the ans ==> "<<countTheReversal(st, str);
    return 0;
}