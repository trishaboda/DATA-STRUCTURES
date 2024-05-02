#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *create(int data)
{
    Node *new_node = new Node(data);
    return new_node;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return create(data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    return root;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data;
        inOrder(root->right);
    }
}


void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data;
    }
}


Node *search(Node *root, int data)
{
    if (root == NULL)
    {
        cout << "Element not found." << endl;
        return root;
    }

    if (root->data == data)
    {
        cout << "Element found." << endl;
        return root;
    }

    if (data > root->data)
    {
        return search(root->right, data);
    }

    return search(root->left, data);
}


int minValue(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        else if (root->right == NULL)
        {
            return root->left;
        }
        root->data = minValue(root->right);
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}

int main()
{
    Node *root = create(10);
    insert(root, 20);
    insert(root, 15);
    insert(root, 25);
    insert(root, 18);
    insert(root, 22);
    insert(root, 14);
    search(root, 19);

    root = deleteNode(root, 10);
    inOrder(root);

    return 0;
}
