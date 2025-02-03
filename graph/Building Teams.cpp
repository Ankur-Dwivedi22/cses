#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &adj, int col, int node, vector<int> &color)
{
    color[node] = col;

    for (auto adjNode : adj[node])
    {
        if (color[adjNode] == -1)
        {
            if (!isBipartite(adj, !col, adjNode, color))
                return false;
                
        }
        else if (color[adjNode] == col)
            return false;
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartite(adj, 1, i, color))
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            cout << 2 << " ";
        }
        else
        {
            cout << 1 << " ";
        }
    }
    cout << "\n";

    return 0;
}