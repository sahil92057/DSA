#include"iostream"
#include"stack"
using namespace std;

bool isValid(stack<int> &st, string &str){
    for(char ch:str){
        if(ch=='a') st.push(ch);
        else if(ch=='b'){
            if(!st.empty() && st.top()=='a')st.push(ch);
            else return false;
        }else{
            if(ch=='c'){
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    if(!st.empty() && st.top()=='a'){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
    }
    return true;
}


int main (){
    string str="aabcbcc";
    stack<int> st;
    bool ans= isValid(st, str);
    cout<<"this is answer==> "<<ans;
    return 0;
}