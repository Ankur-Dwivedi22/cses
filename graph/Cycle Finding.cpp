#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
        adj[a].push_back(b);
    }

    vector<ll> dist(n + 1, 0), parent(n + 1, -1);
    int last;
    for (int i = 0; i < n; i++)
    {
        last = -1;
        for (auto it : edges)
        {
            int a = it[0];
            int b = it[1];
            int c = it[2];

            if ((dist[a] + c) < dist[b])
            {
                dist[b] = dist[a] + c;
                parent[b] = a;
                last = b;
            }
        }
    }
    if (last == -1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            last = parent[last];
        }
        vector<int> cycle;
        int curr = last;
        while (true)
        {
            cycle.push_back(curr);
            if (curr == last && cycle.size() > 1)
                break;
            curr = parent[curr];
        }
        reverse(cycle.begin(), cycle.end());
        for (int node : cycle)
        {
            cout << node << " ";
        }
        cout << "\n";
    }
}