// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int > arr={1, 1, 2, 2, 3, 3, 4};
    int n = arr.size();
    int ans =0;
    for(int i =0; i<n; i++){
        ans = ans^arr[i];
    }
    cout<<"this is th answer "<<ans; 
    return 0;
}