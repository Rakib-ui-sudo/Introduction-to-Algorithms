#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[1005];
bool vis[1005];
int level[1005];
int parent[1005];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
   // parent[src]=-1;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        //=====

        for(int child : adj_list[par])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
                level[child]=level[par]+1;
                parent[child]=par;
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

    for (int i = 0; i <1005; i++)
    {
        vis[i]=false;
        level[i]=-1;
        parent[i]=-1;
    }

    int src,dst;
    cin>>src>>dst;
    bfs(src);

    // for (int i = 0; i <n; i++)
    // {
    //     cout<<i<<" parent => "<<parent[i]<<endl;
    // }

    vector<int> path;
    int node = dst;
    while (node!=-1)
    {
        //cout<<node<<" ";
        path.push_back(node);
        node=parent[node];
    }
    
    reverse(path.begin(),path.end());
    for (int val : path)
    {
        cout<<val<<" ";
    }
    
    
    
    return 0;
}