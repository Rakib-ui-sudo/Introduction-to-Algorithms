#include <bits/stdc++.h>
using namespace std;
char gride[105][105];
bool vis[105][105];
vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
 
int row, col;

bool valid(int i,int j)
{
    if (i<0|| i>=row || j<0 || j>=col)
    {
        return false;
    }
    else
       return true;
    
}
void dfs(int si, int sj)
{
    cout<<si <<" "<<sj << endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + mv[i].first;
        cj = sj + mv[i].second;
        if(valid(ci,cj)==true &&vis[ci][cj]==false)//valid(ci,cj)==>ati bool function call
        {
            dfs(ci,cj);
            vis[ci][cj]=true;
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
            cin >> gride[i][j];
        }
    }
    memset(vis,false,sizeof(vis));

    int si, sj;
    cin >> si >> sj;
    dfs(si, sj);

    return 0;
}

/*input
 3 4
....
....
....
1 2

*/