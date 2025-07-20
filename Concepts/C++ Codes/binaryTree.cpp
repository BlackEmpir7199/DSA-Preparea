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


void inorder(TreeNode* root){
    if(!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    
    int x;
    cin >> x;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(x);
    q.push(root);

    // basically a level order insert method
    while(!q.empty()){
        
        TreeNode* node = q.front();
        q.pop();
        
        cin >> x;
        if(x!=-1){
            node->left = new TreeNode(x);
            q.push(node->left);
        }

        cin >> x;
        if(x!=-1){
            node->right = new TreeNode(x);
            q.push(node->right);
        }

    }


    inorder(root);

    return 0;
}
