// https://open.kattis.com/problems/wheresmyinternet
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
   public:
    
    Graph(int vertices) : V(vertices), adj(vertices + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int startVertex, vector<bool>& isReachable) {
        stack<int> stack;
        stack.push(startVertex);

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();

            if (!isReachable[currentVertex]) {
                isReachable[currentVertex] = true;

                for (int neighbor : adj[currentVertex]) {
                    if (!isReachable[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
        }
    }
};

int main() {
    int n, m, a, b;
    vector<int> notVisit;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g.addEdge(a, b);
    }
    vector<bool> isReachable(n + 1, false);
    g.DFS(1, isReachable);
    for (int i = 2; i < isReachable.size(); i++) {
        if (!isReachable[i])
            notVisit.push_back(i);
    }
    if (notVisit.empty())
        cout << "Connected" << endl;
    else {
        for (auto& num : notVisit)
            cout << num << endl;
    }
    return 0;
}