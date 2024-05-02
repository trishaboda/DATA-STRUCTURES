#include <iostream>
#include <cstdlib>
#define MAX_VALUE 65536
using namespace std;

class N
{
public:
    int k;
    N *l;
    N *r;
    bool leftTh;
    bool rightTh;
};

class ThreadedBinaryTree
{
private:
    N *root;

public:
    ThreadedBinaryTree()
    {
        root = new N();
        root->r = root->l = root;
        root->leftTh = true;
        root->k = MAX_VALUE;
    }

    void makeEmpty()
    {
        root = new N();
        root->r = root->l = root;
        root->leftTh = true;
        root->k = MAX_VALUE;
    }

    void insert(int key)
    {
        N *p = root;
        for (;;)
        {
            if (p->k < key)
            {
                if (p->rightTh)
                    break;
                p = p->r;
            }
            else if (p->k > key)
            {
                if (p->leftTh)
                    break;
                p = p->l;
            }
            else
            {
                return;
            }
        }
        N *temp = new N();
        temp->k = key;
        temp->rightTh = temp->leftTh = true;
        if (p->k < key)
        {
            temp->r = p->r;
            temp->l = p;
            p->r = temp;
            p->rightTh = false;
        }
        else
        {
            temp->r = p;
            temp->l = p->l;
            p->l = temp;
            p->leftTh = false;
        }
    }

    void displayTree()
    {
        N *temp = root;
        while (!temp->leftTh)
        {
            temp = temp->l;
        }

        while (temp != root)
        {
            cout << temp->k << " ";
            if (temp->rightTh)
            {
                temp = temp->r;
            }
            else
            {
                temp = temp->r;
                while (!temp->leftTh)
                {
                    temp = temp->l;
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    ThreadedBinaryTree tbt;
    cout << "ThreadedBinaryTree\n";
    char ch;
    int c, v;
    while (1)
    {
        cout << "\n1. Insert " << endl;
        cout << "2. Clear" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "Enter integer element to insert: ";
            cin >> v;
            tbt.insert(v);
            break;
        case 2:
            cout << "\nTree Cleared\n";
            tbt.makeEmpty();
            break;
        case 3:
            cout << "Display tree: \n ";
            tbt.displayTree();
            break;
        case 4:
            exit(1);
        default:
            cout << "\nInvalid type! \n";
        }
    }

    cout << "\n";
    return 0;
}