#include <bits/stdc++.h>
using namespace std;

#define INF 1e18 
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
    }

    vector<ll> dist(n+1, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        ll d = it.first;
        int node = it.second;

        if (d > dist[node]) continue;

        for (auto it : adj[node])
        {
            ll edw = it.second;
            int adjNode = it.first;

            if (d + edw < dist[adjNode])
            {
                dist[adjNode] = d + edw;
                pq.push({d + edw, adjNode});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
}