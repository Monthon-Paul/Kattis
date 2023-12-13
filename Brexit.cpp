// https://open.kattis.com/problems/brexit
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

// Set of leaving countries
unordered_set<int> leaving;

/**
 * keep track of if contry is leaving
 * & neighbors list.
 **/
struct country {
    double neighborsLeave;
    vector<int> neighbors;
};

/* make a Graph */
class Graph {
    int vertices;
    vector<country> adjacentList;

   public:
    Graph(int vertices);
    void addEdge(int a, int b);
    void BFS(int leave, int home);
};

/* Default Constructor */
Graph::Graph(int vertex) : vertices(vertex) {
    /* initialize every country */
    for (int i = 0; i < vertex + 1; i++) {
        country c;
        c.neighborsLeave = 0.0;
        adjacentList.push_back(c);
    }
}

/* map each verticies to each other */
void Graph::addEdge(int a, int b) {
    /* since this is an undirected graph*/
    adjacentList[a].neighbors.push_back(b);
    adjacentList[b].neighbors.push_back(a);
}

/* Conduct BFS */
void Graph::BFS(int leave, int home) {
    // Create a queue
    queue<int> queue;

    // Mark the leave vertex as first enqueue & search
    queue.push(leave);

    while (!queue.empty()) {
        int curr = queue.front();
        queue.pop();

        /* if country have left than continue */
        if (leaving.count(curr)) continue;

        if (adjacentList[curr].neighborsLeave / adjacentList[curr].neighbors.size() >= 0.5 || curr == leave) {
            /* Mark vertex as leaving */
            leaving.insert(curr);
            if (curr == home) break;

            for (auto &neighbor : adjacentList[curr].neighbors) {
                // mark neighbor leaving and enqueue it
                adjacentList[neighbor].neighborsLeave++;
                if(!leaving.count(neighbor)) 
                    queue.push(neighbor);
            }
        }
    }
}

int main() {
    int vertex, edge, home, leave, a, b;

    // Read input
    cin >> vertex >> edge >> home >> leave;

    // Create Graph
    Graph graph(vertex);

    // Add every vertieces & edge combination
    for (int i = 0; i < edge; i++) {
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    // if home is leaving, then leave */
    if (home == leave) {
        cout << "leave" << endl;
        return 0;
    }

    // perform BFS
    graph.BFS(leave, home);

    if (leaving.count(home))
        cout << "leave" << endl;
    else
        cout << "stay" << endl;

    return 0;
}