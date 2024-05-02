#include <iostream>
using namespace std;

class graphnode
{
    int vertex;
    graphnode *next;

public:
    graphnode(int n = 0)
    {
        vertex = n;
        next = NULL;
    }
    friend class listgraph;
};

class listgraph
{
    graphnode *List[3];
    int n;

public:
    listgraph(int nov)
    {
        n = nov;
        for (int j = 0; j < n; j++)
        {
            List[j] = NULL;
        }
    }
    void create();
    void display();
};

void listgraph::create()
{
    int i, j;
    graphnode *newnode, *temp;
    char ans;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "Is there an edge in between " << i + 1 << " and " << j + 1 << "? ";
            cin >> ans;
            if (ans == 'y')
            {
                newnode = new graphnode(j + 1);
                if (List[i] == NULL)
                {
                    List[i] = temp = newnode;
                }
                else
                {
                    temp->next = newnode;
                    temp = newnode;
                }
            }
        }
    }
}

void listgraph::display()
{
    graphnode *temp;
    int i;
    for (i = 0; i < n; i++)
    {
        cout << endl;
        cout << "vertex " << i + 1 << " -> ";
        temp = List[i];
        while (temp != NULL)
        {
            cout << "v" << temp->vertex << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
}

int main()
{
    listgraph l(3); // Create a graph with 5 vertices
    l.create();
    l.display();
    return 0;
}