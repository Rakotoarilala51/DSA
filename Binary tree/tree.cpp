#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node (int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};
node* buildTree(){
    int d;
    cin>>d;
    if(d==-1) return NULL;
    node* n= new node(d);
    n->left=buildTree();
    n->right=buildTree();

}
int main(){
    
}