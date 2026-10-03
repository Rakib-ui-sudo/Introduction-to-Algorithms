#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[1005];
bool vis[1005];
int level[1005];

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
                level[child]= level[par]+1;
            }
        }
        
    }
    
}
int main()
{
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    for (int i= 0; i<1005; i++)
    {
        vis[i]=false;
        level[i]=-1;
    }

    int src,dst;
    cin>>src>>dst;
    bfs(src);
    cout<<level[dst];
    return 0;
}