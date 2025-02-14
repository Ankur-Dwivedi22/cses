#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj, int &node, vector<int> &parent)
{
    vis[i] = 1;
    pathVis[i] = 1;

    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            parent[it] = i;
            if (dfs(it, vis, pathVis, adj, node, parent))
                return true;
        }
        else if (pathVis[it])
        {
            node = it;
            parent[it] = i;
            return true;
        }
    }

    pathVis[i] = 0;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<int> vis(n + 1, 0);
    vector<int> pathVis(n + 1, 0);
    vector<int> parent(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int node = i;
            if (dfs(i, vis, pathVis, adj, node, parent))
            {
                vector<int> path;
                int temp = node;
                path.push_back(node);
                while (true)
                {
                    node = parent[node];
                    path.push_back(node);
                    if (node == temp)
                        break;
                }
                reverse(path.begin(), path.end());
                cout << path.size() << "\n";
                for (int it : path)
                {
                    cout << it << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}