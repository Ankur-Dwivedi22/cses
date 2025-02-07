#include <bits/stdc++.h>
using namespace std;

#define INF 1e18
typedef long long ll;
typedef pair<ll, ll> pll;

void dijkstra(int start, vector<vector<pll>> &adj, vector<ll> &cost)
{
    cost[start] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        ll c = it.first;
        int node = it.second;

        if(c > cost[node]) continue;

        for (auto it : adj[node])
        {
            int edW = it.second;
            int adjNode = it.first;

            if (edW + c < cost[adjNode])
            {
                cost[adjNode] = edW + c;
                pq.push({cost[adjNode], adjNode});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pll>> graph(n + 1);
    vector<vector<pll>> rev_graph(n + 1);
    vector<vector<ll>> edges;
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
        graph[a].push_back({b, c});
        rev_graph[b].push_back({a, c});
    }

    vector<ll> cost1(n + 1, INF), cost2(n + 1, INF);

    dijkstra(1, graph, cost1);
    dijkstra(n, rev_graph, cost2);
    ll ans = INF;
    for (auto it : edges)
    {
        int a = it[0];
        int b = it[1];
        int c = it[2];

        ans = min(ans, cost1[a] + cost2[b] + (c / 2));
    }

    cout << ans << "\n";
}