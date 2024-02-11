#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graphComplement(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> complement(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (graph[i][j] == 0)
                    complement[i][j] = 1;
            }
        }
    }
    return complement;
}

bool isBipartite(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int neighbor = 0; neighbor < n; ++neighbor) {
                    if (graph[curr][neighbor]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[curr];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[curr]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    // vector<vector<int>> graph = {
    //     {0, 1, 0, 0},
    //     {1, 0, 1, 1},
    //     {0, 1, 0, 1},
    //     {0, 1, 1, 0}
    // };
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };
    vector<vector<int>> complement = graphComplement(graph);
    // for (const auto& row : complement) {
    //     for (int val : row) {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    if (isBipartite(complement)) {
        cout << "The graph CAN be divided into two Cliques" << endl;
    } else {
        cout << "The graph CANNOT be divided into two Cliques" << endl;
    }
    return 0;
}
// time complexity: O(V^3)
// space complexity: O(V^2)