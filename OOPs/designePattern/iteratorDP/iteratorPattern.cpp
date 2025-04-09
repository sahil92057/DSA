#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={1,2,3,4,5,6,7,8,9,10};
    for(vector<int>::iterator it= v.begin(); it!=v.end(); it++){
        cout<<*it<<",";
    }

    for(vector<int>::reverse_iterator it= v.rbegin(); it!=v.rend(); ++it){
        cout<<*it<<",";
    }
    
    
    
    return 0;
}