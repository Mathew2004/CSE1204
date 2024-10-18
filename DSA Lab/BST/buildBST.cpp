#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    // Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insertBST(Node *root, int val ){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left, val);
    }else{
        root->right = insertBST(root->right, val);
    }
    return root;
};

void inOrder(Node *root){
    if(root == NULL){
        return;
    }
     
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    
  
}


int main(){
    Node *root = NULL;
    root = insertBST(root, 50);
    insertBST(root, 10);
    insertBST(root, 20);
    insertBST(root, 190);
    insertBST(root, 90);
    insertBST(root, 100);
    
    inOrder(root);


    
}