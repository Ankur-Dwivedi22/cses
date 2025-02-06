#include <bits/stdc++.h>
using namespace std;

#define INF 1E18
typedef long long ll;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> adj(n + 1, vector<ll>(n + 1, INF));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], (ll)c);
        adj[b][a] = min(adj[a][b], (ll)c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                adj[i][j] = 0;
            }
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] == INF)
            {
                adj[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << adj[a][b] << "\n";
    }
}