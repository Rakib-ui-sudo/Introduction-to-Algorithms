#include<bits/stdc++.h>
using namespace std;
char gride[105][105];
int vis[105][105];
vector<pair<int,int>>mv= {{-1,0},{1,0},{0,-1},{0,1}};
int row,col;

bool valid(int i,int j)
{
    // সারি ও কলাম সীমানার বাইরে গেলে false
    if (i < 0 || i >= row || j < 0 || j >= col)
    {
        return false;
    }
    else{
        return true;
    }
}

void bfs(int si,int sj)
{
   queue<pair<int,int>>q;
   q.push({si,sj});
   vis[si][sj]=true;

   while (!q.empty())
   {
       pair<int,int> par = q.front();
       q.pop();

       int par_i= par.first;
       int par_j = par.second;
       
       cout<<par_i<<" "<<par_j<<endl;

       for(int i = 0; i< 4; i++)
       {
           int ci = par_i + mv[i].first;
           int cj = par_j + mv[i].second;

           if (valid(ci,cj)==true && vis[ci][cj]==false)
           {
                q.push({ci,cj});
                vis[ci][cj]=true;
           }
           
       }
   }
   

}

int main()
{
    cin>>row>>col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>gride[i][j];
        }
        
    }
    memset(vis,false,sizeof(vis));

    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);
    
    return 0;
}