#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj_list[2005];
int dis[2005];

void bfs(int src){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, src}); // {distance, node}
    dis[src] = 0;

    while (!q.empty())
    {
        pair<int,int> par = q.top();
        q.pop();

        int Par_node = par.second;
        int par_dis = par.first;


        for(auto child : adj_list[Par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if(par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                q.push({dis[child_node], child_node});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }
    
    for (int i = 1; i <=n; i++)
    {
        dis[i] = INT_MAX;
    }
  
    bfs(1);

    for (int i = 1; i <=n; i++)
    {
         cout << dis[i] << " ";
    }
    cout << "\n";
    
    return 0;
}