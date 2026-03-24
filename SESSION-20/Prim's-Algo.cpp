//           <<<--- Prim's Algorithm for Minimum Spanning Tree (MST) --->>>

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    key[0] = 0;
    pq.push({0, 0});

    int totalWeight = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if(inMST[u]) continue;

        inMST[u] = true;
        totalWeight += wt;

        for(auto &it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if(!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, v});
            }
        }
    }

    cout << totalWeight << endl;
    return 0;
}