#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int>adj_list[N];
bool vis[N];
int val =0;

void dfs(int src)
{
    vis[src]=true;
    val++;
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
    int nod;
    cin>>nod;
    dfs(nod);
    cout<<val;

    return 0;
}