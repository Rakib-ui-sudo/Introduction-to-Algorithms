#include<bits/stdc++.h>
using namespace std;

int n, m;
char gride[1001][1001];
bool vis[1001][1001];

vector<pair<int,int>> direc = {
    {0,-1},
    {0,1},
    {-1,0},
    {1,0}
};


bool valid(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }

    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for(int i = 0; i < 4; i++)
    {
        int ci = si + direc[i].first;
        int cj = sj + direc[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && gride[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> gride[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(gride[i][j] == '.' && !vis[i][j])
            {
                cnt++;       // নতুন একটি component পাওয়া গেছে
                dfs(i, j);   // পুরো component visit করো.
            }
        }
    }

    cout << cnt << endl;

    return 0;
}