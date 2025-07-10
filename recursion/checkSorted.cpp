// #include <bits/stdc++.h>
#include "iostream"
using namespace std;


bool checkSorted(vector<int> arr, int curr, int prev, int i){
    cout<<i<<endl;
    if( i>= arr.size() ) return true;
    if(prev> curr) return false;
   
    bool ans = checkSorted(arr, arr[i], arr[i-1], ++i);
    return ans;
}

int main() {
  vector<int> arr={10, 20, 19, 40, 50};
  bool ans = checkSorted(arr, arr[1], arr[0], 1);
  cout<<"this is the answer "<<ans;
}
