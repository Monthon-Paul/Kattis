// https://open.kattis.com/problems/pickupsticks
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<int> inDegrees;

   public:
    Graph(int vertices) : V(vertices), adj(vertices + 1), inDegrees(vertices + 1, 0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        inDegrees[v]++;
    }
    /* Kahn's algorithm from https://en.wikipedia.org/wiki/Topological_sorting 
        quite interesting */
    void topologicalSort() {
        vector<int> result;
        queue<int> queue;

        // Enqueue in-degree 0
        for (int i = 1; i < V + 1; ++i) {
            if (inDegrees[i] == 0)
                queue.push(i);
        }

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            result.push_back(current);

            // Reduce in-degree & enqueue in-degree is 0
            for (auto& neighbor : adj[current]) {
                inDegrees[neighbor]--;
                if (inDegrees[neighbor] == 0) {
                    queue.push(neighbor);
                }
            }
        }
        // Check for a cycle
        if (result.size() != V) {
            cout << "IMPOSSIBLE" << endl;
            return;
        } else {
            for (auto& vertex : result)
                cout << vertex << endl;
        }
    }
};

int main() {
    int n, m, a, b;
    cin >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.topologicalSort();
    return 0;
}