#include <bits/stdc++.h>
using namespace std;

bool isValid(int r, int c, int n, int m)
{
    return (r >= 0 && r < n && c >= 0 && c < m);
}
void dfs(int r, int c, vector<vector<char>> &v, vector<vector<int>> &vis)
{
    int n = v.size(), m = v[0].size();

    vis[r][c] = 1;

    vector<int> dr = {0, -1, 0, +1};
    vector<int> dc = {-1, 0, +1, 0};

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (isValid(nr, nc, n, m) && !vis[nr][nc] && v[nr][nc] == '.')
        {
            dfs(nr, nc, v, vis);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && v[i][j] == '.')
            {
                ct++;
                dfs(i, j, v, vis);
            }
        }
    }
    cout << ct << "\n";
}