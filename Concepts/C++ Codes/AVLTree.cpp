#include <iostream>

using namespace std;

struct Node
{
    int data;
    int height;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr), height(0) {}
};

class AVLTree
{
private:
    int getHeight(Node *node)
    {
        return node ? node->height : -1;
    }

    int getBalanceFactor(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(Node *node)
    {
        if (node)
        {
            node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        }
    }

    Node *findMin(Node *root)
    {
        Node *node = root;
        while (node && node->left)
        {
            node = node->left;
        }
        return node;
    }
    Node *rightRotate(Node *root)
    {
        Node *child = root->left;
        Node *childRight = child->right;
        child->right = root;
        root->left = childRight;
        updateHeight(root);
        updateHeight(child);
        return child;
    }

    Node *leftRotate(Node *root)
    {
        Node *child = root->right;
        Node *childLeft = child->left;
        child->left = root;
        root->right = childLeft;
        updateHeight(root);
        updateHeight(child);
        return child;
    }

    Node *insertHelper(Node *root, int key)
    {

        if (!root)
            return new Node(key);

        if (root->data > key)
        {
            root->left = insertHelper(root->left, key);
        }
        else if (root->data < key)
        {
            root->right = insertHelper(root->right, key);
        }
        else
        {
            return root;
        }

        updateHeight(root);

        int balanceFactor = getBalanceFactor(root);

        // LL
        if (balanceFactor > 1 && root->left->data > key)
        {
            return rightRotate(root);
        }

        // RR
        if (balanceFactor < -1 && root->right->data < key)
        {
            return leftRotate(root);
        }

        // LR
        if (balanceFactor > 1 && root->left->data < key)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // RL
        if (balanceFactor < -1 && root->right->data > key)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node *deleteHelper(Node *root, int key)
    {
        if (!root)
            return nullptr;

        if (root->data > key)
        {
            root->left = deleteHelper(root->left, key);
        }
        else if (root->data < key)
        {
            root->right = deleteHelper(root->right, key);
        }
        else
        {
            // case 1: leaf node
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }

            // case 2: one child
            if (!root->left)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // case 3: two children
            Node *minNode = findMin(root->right);
            root->data = minNode->data;
            root->right = deleteHelper(root->right, minNode->data);
        }

        updateHeight(root);

        int balanceFactor = getBalanceFactor(root);

        // LL
        if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)
        {
            return rightRotate(root);
        }

        // RR
        if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0)
        {
            return leftRotate(root);
        }

        // LR
        if (balanceFactor > 1 && getBalanceFactor(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // RL
        if (balanceFactor < -1 && getBalanceFactor(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorderHelper(Node *root)
    {
        if (!root)
            return;
        inorderHelper(root->left);
        cout << root->data << " ";
        inorderHelper(root->right);
    }

public:
    Node *root;
    AVLTree() : root(nullptr) {}
    void insert(int key)
    {
        root = insertHelper(root, key);
    }
    void remove(int key)
    {
        root = deleteHelper(root, key);
    }
    void inorder()
    {
        inorderHelper(root);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.inorder();

    tree.insert(15);
    tree.inorder();

    tree.insert(5);
    tree.insert(3);
    tree.inorder();

    tree.remove(20);
    tree.inorder();

    tree.remove(3);
    tree.inorder();
    
    return 0;
}