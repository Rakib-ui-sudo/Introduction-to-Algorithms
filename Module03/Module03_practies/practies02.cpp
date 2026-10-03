#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int>adj_list[N];
bool vis[N];

void dfs(int src)
{
    vis[src]=true;
    for(int child : adj_list[src])
    {
        if (vis[child]==false)
        {
              dfs(child);
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

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i]==false)
        {
            dfs(i);
            count++;
        }
        
    }
    
    cout<<count;
    return 0;
}