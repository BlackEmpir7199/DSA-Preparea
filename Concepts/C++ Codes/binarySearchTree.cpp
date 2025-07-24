#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int val;
        Node *left,*right;

        Node(int val){
            this->val = val;
            this->left = this->right = NULL;
        }

};





// print in sorted order
void inOrder(Node* root){
    if(!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}


// insert func using recursion
Node* insert(Node* root, int val){
    if(!root){
        Node* temp = new Node(val);
        return temp;
    }
    if(root->val>val)
    root->left = insert(root->left,val);
    else
    root->right = insert(root->right,val);

    return root;
}

// using loop
Node* insertLoop(Node* root, int val){
    Node* temp = new Node(val);
    if(!root){
        return temp;
    }
    Node* ptr = root;
    while(ptr){
        if(ptr->val>val){
            if(!ptr->left){
                ptr->left = temp;
                break;
            }
            else{
                ptr=ptr->left;
            }
        }
        else{
            if(!ptr->right){
                ptr->right = temp;
                break;
            }   
            else{
                ptr=ptr->right;
            }
        }
    }
    return root;
}

int main(){
    int arr[6] = {5,4,2,1,25,9};

    Node* root = NULL;

    for(int i=0;i<6;i++){
        root=insert(root,arr[i]);
    }

    inOrder(root);
    return 0;   
}