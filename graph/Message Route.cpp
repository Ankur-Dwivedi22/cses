#include <bits/stdc++.h>
using namespace std;

int bfs(int start, vector<vector<int>> &adj, int n, vector<int> &ans)
{
    vector<int> parent(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    queue<pair<int, int>> q;
    vector<int> dist(n + 1, 1e9);
    dist[start] = 0;
    q.push({0, start});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int node = it.second;

        if (node == n)
        {
            while (node != start)
            {
                ans.push_back(node);
                node = parent[node];
            }
            ans.push_back(start);
            reverse(ans.begin(), ans.end());
            return dist[n];
        }

        for (auto adjNode : adj[node])
        {
            if (1 + dis < dist[adjNode])
            {
                dist[adjNode] = 1 + dis;
                parent[adjNode] = node;
                q.push({1 + dis, adjNode});
            }
        }
    }

    return -1;
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

    vector<int> ans;
    int start = 1;
    int flag = bfs(start, adj, n, ans);

    if (flag != -1)
    {
        cout << ans.size() << "\n";
        for (int node : ans)
        {
            cout << node << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}