#include <bits/stdc++.h>
using namespace std;

void topo_sort_bfs(vector<vector<int>>& adj, vector<int>& indegree, vector<bool>& visit, vector<int>& ans) {
    queue<int> q1;
    for (int j = 0; j < indegree.size(); j++) {
        if (indegree[j] == 0) {
            q1.push(j);
        }
    }

    while (!q1.empty()) {
        int top = q1.front();
        q1.pop();
        for (int i = 0; i < adj[top].size(); i++) {
            indegree[adj[top][i]]--;
            if (indegree[adj[top][i]] == 0) {
                visit[adj[top][i]] = true;
                q1.push(adj[top][i]);
            }
        }
        ans.push_back(top);
    }
}

void bfs(int start, vector<vector<int>>& adj, int v) {
    vector<bool> visited(v, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
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

    vector<bool> visit(v, false);
    vector<int> indegree(v, 0);
    vector<int> ans;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }

    topo_sort_bfs(adj, indegree, visit, ans);

    cout << "\nTopological Sort:\n";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "\n";

    int startNode;
    cout << "Enter start node for BFS: ";
    cin >> startNode;

    cout << "BFS Traversal from node " << startNode << ":\n";
    bfs(startNode, adj, v);
    cout << "\n";

    return 0;
}
