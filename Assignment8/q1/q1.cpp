#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int find(int x) {
    if(x==p[x]) return x;
    return p[x] = find(p[x]);
}

bool unite(int u, int v) {
    int x = find(u);
    int y = find(v);
    if(x==y) return false;
    p[y]=x;  return true;
}

int main() {
    array<int,3> e; int ans=0;
    int n, m; cin >> n >> m;
    int u, v, w; p.resize(n+1);
    for(int i=0; i<n; ++i) p[i] = i;
    priority_queue<array<int,3>> Q;
    for(int i=0; i<m; ++i) {
        cin >> u >> v >> w;
        e = {w, u, v};
        Q.push(e);
    }
    while(!Q.empty()) {
        auto [w_e, v1, v2] = Q.top();
        Q.pop();
        if(unite(v1,v2)) ans += w_e;
    }
    cout << ans << "\n";
}