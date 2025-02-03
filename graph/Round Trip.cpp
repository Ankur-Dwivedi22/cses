#include <bits/stdc++.h>
using namespace std;

vector<int> parent, vis;
vector<vector<int>> adj;
int cycle_start = -1, cycle_end = -1;

// Optimized DFS function to find a cycle
bool dfs(int node, int par)
{
    vis[node] = 1;

    for (int adjNode : adj[node])
    {
        if (adjNode == par)
            continue; // Ignore the edge leading back to parent

        if (!vis[adjNode])
        {
            parent[adjNode] = node;
            if (dfs(adjNode, node))
                return true;
        }
        else
        {
            // Cycle detected
            cycle_start = adjNode;
            cycle_end = node;
            return true;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    // Read input graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Single DFS to detect a cycle
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && dfs(i, -1))
            break;
    }

    // If no cycle found, print "IMPOSSIBLE"
    if (cycle_start == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Reconstruct the cycle path
    vector<int> path;
    path.push_back(cycle_start);

    int node = cycle_end;
    while (node != cycle_start)
    {
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(cycle_start);

    // Output the cycle
    cout << path.size() << "\n";
    for (int city : path)
    {
        cout << city << " ";
    }
    cout << "\n";

    return 0;
}
