#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int a, b, c;

    edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<edge> adj_list;
    int dis[250];
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list.push_back(edge(a, b, c));
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[0] = 0;

    for (int i = 0; i < n - 1; i++)//bellman ford.....
    {
        for (auto edj : adj_list)
        {
            int a, b, c;
            a = edj.a;
            b = edj.b;
            c = edj.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }

    }

    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << " " << endl;
    }

    return 0;
}
