#include <iostream>
using namespace std;

class Graph
{
private:
    int numVertices;
    int **adjMatrix; 

public:
    Graph(int V)
    {
        numVertices = V;
        adjMatrix = new int *[V];
        for (int i = 0; i < V; i++)
        {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int v, int w)
    {
        adjMatrix[v][w] = 1;
    }

    void deleteEdge(int v, int w)
    {
        adjMatrix[v][w] = 0;
    }

    void displayGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << "Adjacent to vertex " << i << ": ";
            for (int j = 0; j < numVertices; j++)
            {
                if (adjMatrix[i][j] == 1)
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }

    ~Graph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main()
{
    int numVertices, choice, vertex, edge;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph g(numVertices);

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Display Graph\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the vertices (u v) to add edge: ";
            cin >> vertex >> edge;
            g.addEdge(vertex, edge);
            break;
        }
        case 2:
        {
            cout << "Enter the vertices (u v) to delete edge: ";
            cin >> vertex >> edge;
            g.deleteEdge(vertex, edge);
            break;
        }
        case 3:
            g.displayGraph();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}