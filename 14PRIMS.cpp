#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of vertices

class Prims
{
    public:
    void createGraph(int cost[MAX][MAX], int &n)
    {
        cout << "Enter the number of vertices: ";
        cin >> n;

        cout << "Enter the adjacency cost matrix:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> cost[i][j];
            }
        }
    }

    int findMinCostVertex(int n, int minCost[MAX], bool inTree[MAX])
    {
        int minCostVertex = -1;
        for (int v = 0; v < n; v++)
        {
            if (!inTree[v] && (minCostVertex == -1 || minCost[v] < minCost[minCostVertex]))
            {
                minCostVertex = v;
            }
        }
        return minCostVertex;
    }

    void findMinimumSpanningTree(int n, int cost[MAX][MAX])
    {
        int minCost[MAX];
        bool inTree[MAX];

        for (int i = 0; i < n; i++)
        {
            minCost[i] = 1000; // Initialize to a large value
            inTree[i] = false;
        }

        int startVertex = 0; // Start with vertex 0
        minCost[startVertex] = 0;

        int edgesAdded = 0;
        int sum = 0;

        while (edgesAdded < n - 1)
        {
            int u = findMinCostVertex(n, minCost, inTree);

            if (u == -1)
            {
                // If we can't find a suitable vertex to add, it means the graph is not connected.
                cout << "No spanning tree found!" << endl;
                return;
            }

            inTree[u] = true;

            for (int v = 0; v < n; v++)
            {
                if (!inTree[v] && cost[u][v] < minCost[v])
                {
                    minCost[v] = cost[u][v];
                }
            }

            edgesAdded++;
        }

        cout << "Minimum Spanning Tree Edges:" << endl;
        for (int v = 1; v < n; v++)
        {
            cout << "Edge " << v - 1 << " - " << v << " with cost " << minCost[v] << endl;
            sum += minCost[v];
        }
        cout << "Total cost of MST: " << sum;
    }
};

int main()
{
    int n; // Number of vertices
    int cost[MAX][MAX];

    Prims p;
    p.createGraph(cost, n);
    p.findMinimumSpanningTree(n, cost);

    return 0;
}
