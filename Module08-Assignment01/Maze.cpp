#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int, int>> d = {{0,1},{0,-1},{-1,0},{1,0}};//R,L,U,D
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
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D'))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {par_i, par_j};
            }
        }
    }
}

int main()
{
    cin >> row >> col;

    int si, sj;
    int di, dj;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }

            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));

    bfs(si,sj);

    if (vis[di][dj]==true)
    {
        // D থেকে R-এর দিকে backtrack
        int i = di;
        int j = dj;

        while (i!=-1 && j!=-1)
        {
            if (grid[i][j] == '.')
                grid[i][j] = 'X';

            int pi = parent[i][j].first;
            int pj = parent[i][j].second;

             i = pi;
             j = pj;

            // if(i == -1 && j == -1)
            //    break;

           
        }
    }
    
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j];
        }

        cout <<endl;
    }

    return 0;
}