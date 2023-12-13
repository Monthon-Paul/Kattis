// https://open.kattis.com/problems/charlesincharge
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long limit = INT64_MAX;

class Graph {
    int V;
    vector<vector<pair<int, long>>> adj;  // Adjacency list: pair represents (vertex, weight)

   public:
    vector<long> distance;
    vector<int> path;
    Graph(int vertices);
    void addEdge(int v, int w, long weigt);
    long dijkstra(int source);
};

Graph::Graph(int vertices) : V(vertices + 1) {
    adj.resize(V);
    distance.resize(V);
    path.resize(V);
}

// Function to add an edge to the graph with weight
void Graph::addEdge(int u, int v, long weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
}

// Dijkstra's algorithm to find the shortest path from a source vertex
long Graph::dijkstra(int source) {
    fill(distance.begin(), distance.end(), INT64_MAX);
    fill(path.begin(), path.end(), -1);
    vector<bool> visited(V, false);

    distance[source] = 0;

    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            long weight = neighbor.second;

            if (!visited[v] && weight < limit && distance[u] + weight < distance[v]) {
                path[v] = u;
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
    // return shortest path
    return distance[V - 1];  // offset by one
}

int main() {
    int vertex, edge, x, c1, c2;
    long weight, maxWeight;

    // read input
    cin >> vertex >> edge >> x;

    // Create Graph
    Graph graph(vertex);

    // Add every vertieces & edge combination with weights
    for (int i = 0; i < edge; i++) {
        cin >> c1 >> c2 >> weight;
        graph.addEdge(c1, c2, weight);
    }

    int source = 1;  // Source vertex
    long shortestpath = graph.dijkstra(source);
    double maxdist = shortestpath * (1.0 + x / 100.0);  // perfrom calculation

    while (shortestpath <= maxdist) {
        maxWeight = -1L;
        long curr = shortestpath;
        for (int n = vertex; graph.path[n] != -1; ) {
            n = graph.path[n];
            maxWeight = max(maxWeight, curr - graph.distance[n]);
            curr = graph.distance[n];
        }
        limit = maxWeight;
        shortestpath = graph.dijkstra(source);
    }

    cout << maxWeight << endl;

    return 0;
}