#include <iostream>
#include <stack>
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
    void recursiveDFS(int startVertex);
    void iterativeDFS(int startVertex);
    void recursiveDFSTraversal(int vertex, bool visited[]);
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

void listgraph::recursiveDFSTraversal(int vertex, bool visited[])
{
    visited[vertex] = true;
    cout << "v" << vertex + 1 << " -> ";

    graphnode *temp = List[vertex];
    while (temp != NULL)
    {
        int adjVertex = temp->vertex - 1;
        if (!visited[adjVertex])
        {
            recursiveDFSTraversal(adjVertex, visited);
        }
        temp = temp->next;
    }
}

void listgraph::recursiveDFS(int startVertex)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    cout << "Recursive DFS: ";
    recursiveDFSTraversal(startVertex, visited);

    delete[] visited;
}

void listgraph::iterativeDFS(int startVertex)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    stack <int> stack;
    visited[startVertex] = true;
    stack.push(startVertex);

    cout << "\nIterative DFS: ";
    while (!stack.empty())
    {
        startVertex = stack.top();
        cout << "v" << startVertex + 1 << " -> ";
        stack.pop();

        graphnode *temp = List[startVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->vertex - 1;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                stack.push(adjVertex);
            }
            temp = temp->next;
        }
    }

    delete[] visited;
}

int main()
{
    listgraph l(3); // Create a graph with 5 vertices
    l.create();
    l.display();

    int startVertex;
    cout << "\nStarting vertex for DFS: ";
    cin >> startVertex;

    l.recursiveDFS(startVertex - 1);
    l.iterativeDFS(startVertex - 1);
    return 0;
}