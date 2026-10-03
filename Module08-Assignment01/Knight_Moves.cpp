#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];
vector<pair<int, int>> d = {{1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}};
int row, col;

bool valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 8; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        
        cin>>row>>col;
        int src, des;
        cin >> src >> des;
        int dx,dy;
        cin>>dx>>dy;

        int si, sj, di, dj;
        
        si = src;
        sj = des;
        di = dx;
        dj = dy;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(si, sj);

        cout << level[di][dj] << endl;
    }

    return 0;
}