#include <bits/stdc++.h>
using namespace std;

bool isValid(int r, int c, int n, int m)
{
    return (r >= 0 && r < n && c >= 0 && c < m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    int start_r = -1, start_c = -1;

    vector<vector<int>> time(n, vector<int>(m, 1e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
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
            if (v[i][j] == 'M')
            {
                pq.push({0, {i, j}});
                time[i][j] = 0;
            }
        }
    }

    vector<int> dr = {0, -1, 0, +1};
    vector<int> dc = {-1, 0, +1, 0};
    vector<char> dir = {'L', 'U', 'R', 'D'};
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int tm = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (isValid(nr, nc, n, m) && v[nr][nc] != '#')
            {
                if (tm + 1 < time[nr][nc])
                {
                    time[nr][nc] = 1 + tm;
                    pq.push({1 + tm, {nr, nc}});
                }
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    vector<vector<pair<char, pair<int, int>>>> parent(n, vector<pair<char, pair<int, int>>>(m));
    pq.push({0, {start_r, start_c}});
    dist[start_r][start_c] = 0;
    vector<char> path;
    bool flag = false;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int d = it.first;
        int r = it.second.first;
        int c = it.second.second;

        // cout<<d<<" "<<r<<" "<<c<<"\n";

        if (r == n - 1 || c == m - 1 || r == 0 || c == 0)
        {
            while (r != start_r || c != start_c)
            {
                auto it = parent[r][c];
                char ch = it.first;
                int nr = it.second.first;
                int nc = it.second.second;
                path.push_back(ch);
                r = nr;
                c = nc;
            }
            reverse(path.begin(), path.end());
            flag = true;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (isValid(nr, nc, n, m) && v[nr][nc] == '.' && ((1 + d) < time[nr][nc]))
            {
                if (1 + d < dist[nr][nc])
                {
                    dist[nr][nc] = 1 + d;
                    parent[nr][nc] = {dir[i], {r, c}};
                    pq.push({1 + d, {nr, nc}});
                }
            }
        }
    }
    if (flag)
    {
        cout << "YES\n";
        cout << path.size() << "\n";
        for (char ch : path)
        {
            cout << ch;
        }
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}