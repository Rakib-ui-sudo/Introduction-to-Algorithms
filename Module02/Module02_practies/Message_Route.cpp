#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list(100005);
bool vis[100005];
int parent[100005];

void bfs(int src)
{
    queue<int> q;

    q.push(src);
    vis[src] = true;
    parent[src] = -1;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
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

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    bfs(1);

    // n এ পৌঁছানো সম্ভব কিনা
    if (!vis[n])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Path বের করা
    int node = n;
    vector<int> path;

    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    // n -> ... -> 1 থেকে 1 -> ... -> n
    reverse(path.begin(), path.end());

    cout << path.size() << endl;

    for (int x : path)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}