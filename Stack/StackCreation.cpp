#include "iostream"
using namespace std;
class stackImp{
public:
    int top;
    int size;
    int *arr;

    stackImp(int capacity)
    {
        top = -1;
        size = capacity;
        arr = new int[size];
    }

    void push(int x)
    {
        if (top >= size - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }

    void pop(){
        if(top >0){
            top--;
        }else{
            cout<<"Stack underflow";
        }
    }

    void sizeSt(){
        cout<<top+1;
    }
    void empty(){
        if(top==-1) cout<<true<<endl;
        else cout<<false<<endl;
    }
    void getop(){
        if(top==-1) cout<<"Stack underflow"<<endl;
        else  cout<<arr[top];
    }

};




int main (){
    stackImp st(5);
    // st.getop();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // st.getop();
    // st.empty();
    st.pop();
    st.getop();
    // st.sizeSt();

    return 0;
}