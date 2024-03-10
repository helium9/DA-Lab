#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    queue<int> Q;
    int max_path = 0;
    vector<int> deg(n), topological_sort, path(n);
 
    vector<vector<int>> adj = {
        {1, 2, 3, 4},
        {3},
        {3, 4},
        {4},
        {}
    };
    
    for(int i = 0; i < n; ++i) 
        for(int x : adj[i]) deg[x]++;
    
    for(int i = 0; i < n; ++i) 
        if(!deg[i]) path[i] = 0, Q.push(i);
        
        
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        topological_sort.push_back(node);
        
        for(int child : adj[node]) {
            deg[child]--;
            if(!deg[child])
                Q.push(child);           
        }
    }
    
    for(int x : topological_sort) {
        for(int child : adj[x]) {
            path[child] = max(path[child], 1 + path[x]);
            max_path = max(max_path, path[child]);
        }
    }
    
    cout << max_path;
}