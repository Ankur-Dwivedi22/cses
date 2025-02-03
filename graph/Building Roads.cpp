#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    DisjointSet ds(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ds.unionByRank(u, v);
    }

    int ct = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (ds.find(i) == i)
        {
            ct++;
            v.push_back(i);
        }
    }

    cout << ct - 1 << "\n";
    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i - 1] << " " << v[i] << "\n";
    }
}