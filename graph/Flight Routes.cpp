#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define INF LLONG_MAX

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pll>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});

    vector<vector<ll>> dist(n + 1);

    dist[1].push_back(0);

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        ll d = it.first;
        int node = it.second;

        if (dist[node].size() > k)
            continue;

        dist[node].push_back(d);

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            ll edW = it.second;
            ll newD = edW + d;
            pq.push({newD , adjNode});
        }
    }
    for (ll d : dist[n])
    {
        if(k == 0) break;
        cout << d << " ";
        k--;
    }
    cout << "\n";
}