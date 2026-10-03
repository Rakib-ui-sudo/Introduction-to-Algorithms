#include<bits/stdc++.h>
using namespace std;
int row,col;
char grid[1000][1000];
bool vis[1000][1000];
pair<int,int>mv[4]={{-1,0},{0,1},{1,0},{0,-1}};

bool valid(int i,int j){
    return i>=0 && i<row && j>=0 && j<col;
}

void bfs(int si,int sj){
     queue<pair<int,int>>q;
      q.push({si,sj});
      vis[si][sj]=true;
      while (!q.empty())
      {
         pair<int,int> par = q.front();
         q.pop();

         int pi=par.first;
         int pj=par.second;

         for (int i = 0; i <4; i++)
         {
            int ci=pi+mv[i].first;
            int cj=pj+mv[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]=='.'){
                vis[ci][cj]=true;
                q.push({ci,cj});
            }
         }
         
      }
      

}

int main()
{
    cin>>row>>col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <col; j++)
        {
            cin>>grid[i][j];
        }
        
    }

    memset(vis,false,sizeof(vis));
    int cnt=0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j <col; j++)
        {
           if(!vis[i][j]&&grid[i][j]=='.'){
              cnt++;
              bfs(i,j);
           }
        }
        
    }
    cout<<cnt;
    return 0;
}