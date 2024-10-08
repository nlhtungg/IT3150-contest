#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertBST(Node* &root, int data){
    if(root==NULL){
        root = createNode(data);
        return;
    }
    if(data < root->data) insertBST(root->left, data);
    else if(data == root->data) return;
    else insertBST(root->right, data);
}

void preOrder(Node* root){
    if(root==NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    Node* root = NULL;
    while(true){
        string cmd; cin >> cmd;
        if(cmd == "#"){
            preOrder(root);
            return 0;
        } else if(cmd == "insert"){
            int data; cin >> data;
            insertBST(root, data);
        }
    }
}