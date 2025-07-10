#include<iostream>
using namespace std;
#include"algorithm"
#include<queue>

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }
};


Node* createBT(){
    cout<<"Enter the Node value "<<endl;
    int val;cin>>val;
   if(val==-1){
      return NULL;
   }else{
    Node* node = new Node(val);
     
    cout<<"Moving to the left node "<<node->data<<endl;
    node->left= createBT();
     cout<<"Moving to the right node "<<node->data<<endl;
    node->right=createBT();
    return node;
}
}






void preOrderTra(Node* root ){
    if(!root) return;
    cout<<" "<<root->data;
    preOrderTra(root->left);
    preOrderTra(root->right);

}
void inOrderTra(Node* root ){
    if(!root) return;
    preOrderTra(root->left);
    cout<<" "<<root->data;
    preOrderTra(root->right);
}

void postOrderTra(Node* root ){
    if(!root) return;
    preOrderTra(root->left);
    preOrderTra(root->right);
    cout<<" "<<root->data;
}


void levelOrderTra(Node * root ){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* fronNode= q.front();
        q.pop();
        cout<<" "<<fronNode->data;
        if(fronNode->left){
            q.push(fronNode->left);
        }
         if(fronNode->right){
            q.push(fronNode->right);
        }
    }
}

int heightOfBT(Node *root){
    if(!root) return 0;
    return 1+  max(heightOfBT(root->left), heightOfBT(root->right));
}

int diaOfBT(Node* root){
    if(!root) return 0;
    int op1= diaOfBT(root->left);
    int op2= diaOfBT(root->right);
    int op3=1+ heightOfBT(root->left)+heightOfBT(root->right);
    return max(op1, max(op2, op3));
}
int optimisedDiaOfBT(Node* root, int &maxi){
    if(!root) return 0;

    int lh =heightOfBT(root->left);
    int rh=heightOfBT(root->right);
    maxi=max(maxi, lh+rh);
    return maxi;
}

bool balancedBT(Node* root){
    if(!root) return true;
    int lh = heightOfBT(root->left);
    int rh = heightOfBT(root->right);
    bool ans =true;
    if(abs(lh-rh) >1) ans=false;
    
    bool op1=balancedBT(root->left);
    bool op2=balancedBT(root->right);
    return op1 && op2 && ans;
}
int optimisedBalancedBT(Node* root){
    if(!root) return -1;
    int lh = optimisedBalancedBT(root->left);
    if(lh==-1) return -1;
    int rh = optimisedBalancedBT(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh) >1) return -1;
    return max(lh, rh)+1;
}

Node* LCA(Node* root, int p, int q) {
    if (!root) return NULL;
    if (root->data == p || root->data == q) return root;

    Node* lh = LCA(root->left, p, q);
    Node* rh = LCA(root->right, p, q);
    if (lh && rh) return root;
    return lh ? lh : rh;
}


int main (){
    Node* root;
    root=createBT();
    // postOrderTra(root);
    // levelOrderTra(root);
    // int h =heightOfBT(root);
    // int dia=0;
    // dia=diaOfBT(root);
    // int maxi=0;
    // optimisedDiaOfBT(root, maxi);
    // cout<<"this is the dia"<<maxi;
    // cout<<"this is the answer "<< root->data;
    Node* ans = LCA(root, 4, 5);
    cout<<"balanced BT "<< ans->data;
    return 0;
    
}