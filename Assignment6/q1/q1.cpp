#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    queue<int> Q;
    vector<int> deg(n), topological_sort;
 
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
        if(!deg[i]) Q.push(i);
        
        
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
    
    
    for(int x : topological_sort) cout << x << ' ';
}