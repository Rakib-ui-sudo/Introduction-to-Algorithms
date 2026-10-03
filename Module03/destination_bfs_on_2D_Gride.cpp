#include <bits/stdc++.h>
using namespace std;

const int N = 105;
char Gride[N][N];
bool vis[N][N];
int des[N][N];
vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int row, col;

int valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void bfs(int si, int sj)
{

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    des[si][sj]=0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;

       // cout << par_i << " " << par_j << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + mv[i].first;
            int cj = par_j + mv[i].second;
            if (vis[ci][cj] == false && valid(ci, cj) == true && Gride[ci][cj]=='.')
            {
                q.push({ci, cj});
                vis[ci][cj]=true;
                des[ci][cj] = des[par_i][par_j]+1;
            }
        }
    }
}

int main()
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        { 
            cin >> Gride[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    memset(des,-1,sizeof(des));
    int si, sj;
    cin >> si >> sj;

    bfs(si,sj);
    int di,dj;
    cin>>di>>dj;

    cout<<des[di][dj]<<endl;

    return 0;
}

/* input
3 4
....
.#..
.#..
1 2
2 0 
ans 5 */