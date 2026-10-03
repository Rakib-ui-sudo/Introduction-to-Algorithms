#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[1005];
bool vis[1005];

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;

    while (!q.empty())
    {
        int par = q.front();//1
        q.pop();

        cout<<par<<" ";//2

        for (int child : adj_list[par])//3
        {
            if (vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
            }
            
        }
        
    }
    
}
int main()
{
    int n,e;
    cin>>n>>e;
    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    for (int i = 0; i <1005; i++)
    {
        vis[i]= false;
    }
    bfs(0);
    
    return 0;
}