#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *BinarySearchTree(node *root, int val)
{
    node *newNode = new node(val);
    if (root == NULL)
    {
        return newNode;
    }

    node *current = root;
    while (true)
    {
        if (val < current->data)
        {
            if (current->left == NULL)
            {
                current->left = newNode;
                break;
            }
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = newNode;
                break;
            }
            current = current->right;
        }
    }

    return root;
}

void preorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void delete(int n)
{
    
}

int main()
{
    int n, i;
    cout << "Enter the number of nodes you want in the binary tree: ";
    cin >> n;
    int val;
    node *root = nullptr; // Initialize root with nullptr
    for (i = 0; i < n; i++)
    {
        cout << "Value at node " << i + 1 << ": ";
        cin >> val;
        root = BinarySearchTree(root, val); // Update the root with the result of bst() function
    }
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal of bst: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal of bst: ";
    postorder(root);
    cout << endl;
    return 0;
}
