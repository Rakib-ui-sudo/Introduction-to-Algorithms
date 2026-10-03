#include<bits/stdc++.h>
using namespace std;
int row,col;
char grid[1002][1002];
bool vis[1002][1002];
// int mv1[4]={-1,1,0,0};
// int mv2[4]={0,0,-1,1};
pair<int,int>mv[4]= {{-1,0},{1,0},{0,-1},{0,1}};


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
         if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]=='.')
         {
            dfs(ci,cj);
         }
    }
    
}

int main()
{
    cin>>row>>col;
    for (int i = 0; i <row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>grid[i][j];
        }
        
    }
    
    memset(vis,false,sizeof(vis));

    int si,sj,tx,ty;
    cin>>si>>sj;
    cin>>tx>>ty;//tergat val

    dfs(si,sj);

    if (vis[tx][ty]==true)
    {
        cout<<"YES"<<endl;
    }
    else
       cout<<"NO"<<endl;

   

    return 0;
}