#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tarjanSCC(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> low(n, -1), disc(n, -1);
    vector<bool> onStack(n, false);
    stack<int> st;
    vector<vector<int>> SCCs;
    int time = 0;

    function<void(int)> DFS = [&](int u) {
        low[u] = disc[u] = time++;
        st.push(u);
        onStack[u] = true;

        for (int v : graph[u]) {
            if (disc[v] == -1) {
                DFS(v);
                low[u] = min(low[u], low[v]);
            } else if (onStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (low[u] == disc[u]) {
            vector<int> scc;
            int v;
            do {
                v = st.top();
                st.pop();
                onStack[v] = false;
                scc.push_back(v);
            } while (v != u);
            SCCs.push_back(scc);
        }
    };

    for (int i = 0; i < n; ++i) {
        if (disc[i] == -1) {
            DFS(i);
        }
    }
    return SCCs;
}

int main() {
    int n, m; // Number of nodes and edges
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<vector<int>> SCCs = tarjanSCC(graph);

    cout << "Strongly Connected Components:\n";
    for (const auto& scc : SCCs) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
