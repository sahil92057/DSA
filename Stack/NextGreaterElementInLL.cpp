// next greater element in linked list

#include "iostream"
#include "stack"
#include "vector"
using namespace std;

// int main()
// {
//     int arr[6] = {2, 1, 7, 4, 3, 5};
//     stack<int> st;
//     st.push(-1);
//     vector<int> ans;
//    for(int it=5; it>=0; it--)
//     {
//         if (st.top() == -1)
//         {
//             ans.push_back(0);
//             st.push(it);
//         }
//         else
//         {
//             if (st.top() > it)
//             {
//                 ans.push_back(st.top());
//                 st.push(it);
//             }
//             else
//             {
//                 while (st.top() <it && st.top()!=-1)
//                 {
//                     st.pop();
//                 }
//                 if(st.top()>it){
//                    ans.push_back(st.top());
//                 } else ans.push_back(0);
                
//             }
//         }
//     }
//      for(auto it:ans){
//         cout<<" tyutu"<<it;
//      }
//     return 0;
// }




int main (){
    int arr[6]={2, 1, 7, 4, 3, 5};
    vector<int> ans(6);
    stack<int>st;
    for(int i=0; i<6; i++){          
        while(!st.empty() && arr[i]> arr[st.top()]){
            int x = st.top();
            st.pop();
            ans[x]=arr[i];
        }
        st.push(i);
    }
    for(auto it:ans){
        cout<<" "<<it;
    }

    return 0;
}
