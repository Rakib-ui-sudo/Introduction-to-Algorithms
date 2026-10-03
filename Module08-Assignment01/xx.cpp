#include<bits/stdc++.h>
using namespace std;
int row,col;
char grid[1005][1002];
bool vis[1005][1005];
pair<int,int> parent[1005][1005];
pair<int,int>mv[4]= {{0,1},{0,-1},{-1,0},{1,0}};

//ai problem ar jonno dfs kaj korba anh ai podhotita

bool valid(int i,int j)
{
    if(i<0 || i>=row || j<0 || j>=col)
    {
        return false;
    }
    return true;
}

void dfs(int si,int sj)
{
    vis[si][sj]=true;
    for (int i = 0; i <4; i++)
    {
         int ci=si+mv[i].first;
         int cj= sj+mv[i].second;
         if(valid(ci,cj) && !vis[ci][cj] && (grid[ci][cj]=='.'||grid[ci][cj]=='D'))
         {
            vis[si][sj]=true;
            parent[ci][cj]={si,sj};
            dfs(ci,cj);
           
         }
    }
    
}

int main()
{
    cin>>row>>col;
    int si,sj,dx,dy;
    for (int i = 0; i <row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>grid[i][j];

            if(grid[i][j]=='R'){
                si=i;
                sj=j;
            }
            else if(grid[i][j]=='D'){
                 dx=i;
                 dy=j;
            }
        }
        
    }
    
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    dfs(si,sj);

    if(vis[dx][dy])
    {
        int i=dx;
        int j=dy;

        while (i!=-1 && j!=-1 )
        {
            if(grid[i][j]=='.')
            {
                grid[i][j]='X';
            }
            int pi = parent[i][j].first;
            int pj = parent[i][j].second;

             i = pi;
             j = pj;
        }
        
    }

    for (int i = 0; i <row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    
   

    return 0;
}