#include <bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>>& cost) {
    int n = cost.size();
    int N = 1 << n;

    vector<vector<int>> dp(N, vector<int>(n, INT_MAX));

  
    
    dp[1][0] = 0;

    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;

            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;

                dp[mask | (1 << v)][v] =
                    min(dp[mask | (1 << v)][v],
                        dp[mask][u] + cost[u][v]);
            }
        }
    }

    int ans = INT_MAX;

    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[N - 1][i] + cost[i][0]);
    }

    return ans;
}

int main() {
    vector<vector<int>> cost = {
        {0, 111},
        {112, 0}
    };

    cout << tsp(cost);
}