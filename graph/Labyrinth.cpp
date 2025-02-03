#include <bits/stdc++.h>
using namespace std;

bool isValid(int r, int c, vector<vector<char>> &v)
{
    int n = v.size(), m = v[0].size();

    return (r >= 0 && r < n && c >= 0 && c < m);
}

int bfs(int sr, int sc, vector<vector<char>> &v, string &ans)
{
    queue<pair<int, pair<int, int>>> q;
    int n = v.size(), m = v[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[sr][sc] = 0;
    q.push({0, {sr, sc}});

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    vector<int> dr = {0, -1, 0, +1};
    vector<int> dc = {-1, 0, +1, 0};
    vector<int> dir = {'L', 'U', 'R', 'D'};

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        if (v[r][c] == 'B')
        {
            int fr = r, fc = c;
            while (r != sr || c != sc)
            {
                auto p = parent[r][c];
                int pr = p.first, pc = p.second;
                for (int i = 0; i < 4; i++)
                {
                    if (pr + dr[i] == r && pc + dc[i] == c)
                    {
                        ans += dir[i];
                        break;
                    }
                }
                r = pr;
                c = pc;
            }

            reverse(ans.begin(), ans.end());
            return dist[fr][fc];
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isValid(nr, nc, v) && v[nr][nc] != '#' && dis + 1 < dist[nr][nc])
            {
                dist[nr][nc] = 1 + dis;
                parent[nr][nc] = {r, c};
                q.push({dis + 1, {nr, nc}});
            }
        }
    }

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    int start_r = -1, start_c = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
            {
                start_r = i;
                start_c = j;
            }
        }
    }
    string ans = "";
    int flag = bfs(start_r, start_c, v, ans);
    if (flag == -1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        cout << flag << "\n";
        cout << ans << "\n";
    }
}