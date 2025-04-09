#include"iostream"
#include"stack"
using namespace std;

string removeAdjacent(string &str, stack<char> &st){
    for(char ch:str){
        if(st.empty()){
            st.push(ch);
        }else if(ch==st.top()){
            st.pop();
        }else{
            st.push(ch);
        }
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
   reverse(ans.begin(), ans.end());
    return ans;

}


int main(){
    string str="azxxzy";
    stack<char>st;
    cout<<"answer==>> "<<removeAdjacent(str, st);
    return 0;
}

