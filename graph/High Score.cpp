#include <bits/stdc++.h>
using namespace std;
#define INF -1e18
typedef long long ll;
typedef pair<ll, ll> pll;

void bfs(vector<vector<int>> &graph, int start, vector<bool> &reachable)
{
    reachable[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        for (auto adjNode : graph[it])
        {
            if (!reachable[adjNode])
            {
                reachable[adjNode] = true;
                q.push(adjNode);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> adj;
    vector<vector<int>> graph(n + 1), rev_graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        adj.push_back({a, b, x});
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    vector<bool> reachable_from_1(n + 1, false), reachable_to_n(n + 1, false);

    bfs(graph, 1, reachable_from_1);
    bfs(rev_graph, n, reachable_to_n);

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto it : adj)
        {
            ll a = it[0];
            ll b = it[1];
            ll x = it[2];

            if (dist[a] != INF && dist[a] + x > dist[b])
            {
                dist[b] = dist[a] + x;
            }
        }
    }

    for (auto it : adj)
    {
        ll a = it[0];
        ll b = it[1];
        ll x = it[2];

        if (dist[a] != INF && dist[a] + x > dist[b])
        {
            if (reachable_from_1[a] && reachable_to_n[b])
            {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << dist[n] << "\n";
}