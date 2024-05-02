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
    graphnode *List[5];
    int n;
    bool visited[5]; // Added an array to keep track of visited vertices
public:
    listgraph(int nov)
    {
        n = nov;
        for (int j = 0; j < n; j++)
        {
            List[j] = NULL;
            visited[j] = false;
        }
    }
    void create();
    void display();
    void recursiveDFS(int vertex);
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

void listgraph::recursiveDFS(int vertex)
{
    visited[vertex] = true;
    cout << vertex + 1 << " -> ";
    graphnode *temp = List[vertex];
    while (temp != NULL)
    {
        int adjacentVertex = temp->vertex - 1;
        if (!visited[adjacentVertex])
        {
            recursiveDFS(adjacentVertex);
        }
        temp = temp->next;
    }
}

int main()
{
    listgraph a1(3);
    a1.create();
    a1.display();

    cout << "\nDFS starting from vertex 1: ";
    a1.recursiveDFS(0);
    cout << "NULL";
    return 0;
}

