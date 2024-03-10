#include <bits/stdc++.h>
using namespace std;

bool hasLoop = false;

void DFS(vector<vector<int>>& graph, vector<bool>& visited, int u, vector<bool>& inStack) {
    visited[u] = true;
    inStack[u] = true;

    for (int v : graph[u]) {
        if (!visited[v]) {
            DFS(graph, visited, v, inStack);
        } else if (inStack[v]) {
            hasLoop = true;
            return;
        }
    }

    inStack[u] = false;
}

int main() {
    int n = 5;
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 1}, {2, 4}, {3, 5}, {4, 5}, {5, 2}};

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    vector<bool> inStack(n + 1, false);

    for (auto [u, v] : edges) {
        graph[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            DFS(graph, visited, i, inStack);
        }
    }

    if (hasLoop) {
        cout << "Graph has a loop.\n";
    } else {
        cout << "Graph does not have a loop.\n";
    }

    return 0;
}
