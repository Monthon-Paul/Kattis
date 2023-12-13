// https://open.kattis.com/problems/shortestpath1
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;  // Adjacency list: pair represents (vertex, weight)

   public:
    vector<int> distance;
    Graph(int vertices);
    void addEdge(int v, int w, int weight);
    void dijkstra(int source);
};

Graph::Graph(int vertices) : V(vertices) {
    adj.resize(V);
    distance.resize(V);
}

// Function to add an edge to the graph with weight
void Graph::addEdge(int u, int v, int weight) {
    adj[u].push_back({v, weight});
}

// Dijkstra's algorithm to find the shortest path from a source vertex
void Graph::dijkstra(int source) {
    fill(distance.begin(), distance.end(), INT_MAX);
    vector<bool> visited(V, false);

    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            long weight = neighbor.second;

            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
}

int main() {
    int vertex, edge, q, s, n1, n2, w, n;
    // read input
    while (cin >> vertex >> edge >> q >> s) {
        if (vertex == 0 && edge == 0 && q == 0 && s == 0)
            break;
        // Create a new graph every time
        Graph graph(vertex);
        for (int i = 0; i < edge; i++) {
            cin >> n1 >> n2 >> w;
            graph.addEdge(n1, n2, w);
        }
        graph.dijkstra(s);
        for (int i = 0; i < q; i++) {
            cin >> n;
            if (graph.distance[n] != INT_MAX)
                cout << graph.distance[n] << endl;
            else
                cout << "Impossible" << endl;
        }
        cout << endl;
    }
    return 0;
}