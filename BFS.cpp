#include <iostream>
#include <queue>
using namespace std;

class listgraph
{
private:
    int V;
    int **adjMatrix;
    bool *visited;

public:
    listgraph(int vertices)
    {
        V = vertices;
        adjMatrix = new int *[V];
        for (int i = 0; i < V; i++)
        {
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
        visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
    }

    void addEdge(int v, int w)
    {
        adjMatrix[v][w] = 1;
    }

    void dfs(int vertex)
    {
        visited[vertex] = true;
        cout << vertex + 1 << "->";
        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[vertex][i] && !visited[i])
            {
                dfs(i);
            }
        }
    }

    void bfs(int startVertex)
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        queue<int> Q;
        visited[startVertex] = true;
        Q.push(startVertex);

        while (!Q.empty())
        {
            int vertex = Q.front();
            Q.pop();
            cout << vertex + 1 << "->";

            for (int i = 0; i < V; i++)
            {
                if (adjMatrix[vertex][i] && !visited[i])
                {
                    visited[i] = true;
                    Q.push(i);
                }
            }
        }

        delete[] visited;
    }
};

int main()
{
    int numVertices, numEdges;
    cout << "\nEnter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    listgraph g(numVertices);

    cout << "Enter edges (format: vertex1 vertex2):" << endl;
    for (int i = 0; i < numEdges; i++)
    {
        int v, w;
        cin >> v >> w;
        g.addEdge(v - 1, w - 1); // Adjust indices to 0-based
    }

    int startVertex;
    cout << "\nEnter the starting vertex (1-" << numVertices << "): ";
    cin >> startVertex;
    startVertex--; // Adjust to 0-based index

    cout << "\nDFS traversal starting from vertex " << startVertex + 1 << ": ";
    g.dfs(startVertex);
    cout << endl;

    cout << "BFS traversal starting from vertex " << startVertex + 1 << ": ";
    g.bfs(startVertex);
    cout << endl;

    return 0;
}
