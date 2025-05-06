#include <bits/stdc++.h>
using namespace std;

void topo_sort(vector<vector<int>>& adj, stack<int>& s1, vector<bool>& visit, int i) {
    if (visit[i]) return;

    visit[i] = true;
    for (int j = 0; j < adj[i].size(); j++) {
        topo_sort(adj, s1, visit, adj[i][j]);
    }
    s1.push(i);
}

void dfsiter(int start, vector<vector<int>>& adj, int v) {
    vector<bool> visited(v, false);
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
        }

        // Push adjacent nodes in reverse order for correct DFS
        for (int i = adj[node].size() - 1; i >= 0; --i) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                s.push(neighbor);
            }
        }
    }
}

int main() {
    int u, v;
    cout << "Enter number of edges and vertices: ";
    cin >> u >> v;

    vector<vector<int>> adj(v);
    for (int i = 0; i < u; i++) {
        cout << "Enter edge (from to): ";
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Directed graph
    }

    // Topological Sort using DFS
    vector<bool> visit(v, false);
    stack<int> s1;
    for (int i = 0; i < v; i++) {
        if (!visit[i]) {
            topo_sort(adj, s1, visit, i);
        }
    }

    cout << "\nTopological Sort (DFS): ";
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << "\n";

    // Iterative DFS
    int startNode;
    cout << "Enter start node for Iterative DFS: ";
    cin >> startNode;
    cout << "DFS Traversal from node " << startNode << ": ";
    dfsiter(startNode, adj, v);
    cout << "\n";

    return 0;
}
