#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vist[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vist[src] = true;

    while (!q.empty())
    {
        // barkora ana
        int par = q.front();
        q.pop();
        // oi node k niyea kaj
        cout << par << " ";
        // child gulan push kora
        for (int child : adj_list[par])
        {
            if (vist[child] == false)
            {
                q.push(child);
                vist[child] = true;
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
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vist, false, sizeof(vist)); // vist array sob man false
    // for (int i = 0; i <n; i++)
    // {
    //     vist[i]=false;
    // }
    
    bfs(0);
    return 0;
}