//      <<<--- Kruskal's Minimum Spanning Tree (MST) Algorithm --->>>


#include <bits/stdc++.h>
using namespace std;
vector<int> parent, rankk;
int find(int x) {
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if(px == py) return;
    if(rankk[px] < rankk[py])
        parent[px] = py;
    else if(rankk[px] > rankk[py])
        parent[py] = px;
    else {
        parent[py] = px;
        rankk[px]++;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<tuple<int,int,int>> edges;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    parent.resize(V);
    rankk.resize(V, 0);
    for(int i = 0; i < V; i++)
        parent[i] = i;
    int totalWeight = 0;
    for(auto edge : edges) {
        int w = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);
        if(find(u) != find(v)) {
            totalWeight += w;
            unite(u, v);
        }
    }
    cout << totalWeight << endl;
    return 0;
}