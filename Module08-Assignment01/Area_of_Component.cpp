#include<bits/stdc++.h>
using namespace std;
int row,col;
char grid[1005][1002];
bool vis[1005][1005];
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
long long val;
void dfs(int si,int sj)
{
    vis[si][sj]=true;
    val++;
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

    long long mn=INT_MAX;

    for (int i = 0; i <row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(!vis[i][j]&& grid[i][j]=='.')
            { 
                val=0;
                dfs(i,j);
                mn=min(mn,val);
                    
            }
        }
        
    }
    
   if(mn==INT_MAX){
      mn=-1;
      cout<<mn<<endl;
    }  
    else
      cout<<mn;

    return 0;
}