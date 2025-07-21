#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
    public:
        int val;
        TreeNode *left, *right;

        TreeNode(int val)
        {
            this->val = val;
            left = right = nullptr;
        }
};


// This method follows dfs .. ie it goes deep down to filling each nodes left child first -> then right child -> then comes recursion moves up the level and does the same 
TreeNode* recurseGod(){
    int x;
    cin >> x;
    if(x==-1) return NULL;
    
    TreeNode* node = new TreeNode(x);

    node->left = recurseGod();
    node->right = recurseGod();

    return node;
}

void inorder(TreeNode* root){
    if(!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    
    // int x;
    // cin >> x;
    // queue<TreeNode*> q;
    // TreeNode* root = new TreeNode(x);
    // q.push(root);

    //Method 1: basically a level order insert method
    // while(!q.empty()){
        
    //     TreeNode* node = q.front();
    //     q.pop();
        
    //     cin >> x;
    //     if(x!=-1){
    //         node->left = new TreeNode(x);
    //         q.push(node->left);
    //     }

    //     cin >> x;
    //     if(x!=-1){
    //         node->right = new TreeNode(x);
    //         q.push(node->right);
    //     }

    // }

    // Method 2: Enters the God : Recursion!
    TreeNode* root=recurseGod();
    vector<int> vc;
    inorder(root);

    return 0;
}
