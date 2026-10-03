#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int>adj_list[N];
bool vis[N];
int nodes = 0;

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        //===========
          nodes++;
        for(int child : adj_list[par])
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
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));

    vector<int>count;
    for (int i = 0; i < n; i++)
    {
        if (vis[i]==false)
        {
            nodes=0;
            bfs(i);
            count.push_back(nodes);
        }
        
    }
    
    sort(count.begin(),count.end());
    for(int val : count)
    {
        cout<<val<<" ";
    }
    
    return 0;
}