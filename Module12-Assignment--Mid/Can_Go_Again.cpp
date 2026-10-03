#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b;
    long long int c;

    Edge(int a, int b, long long int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

long long int INF = LLONG_MAX;//const

long long int dis[1005];

vector<Edge> edge_list;

int n, e;

bool bellman_ford(int src)
{
    // সব distance INF
    for(int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    // source থেকে source-এর distance 0
    dis[src] = 0;

    // n-1 বার relaxation
    for(int i = 1; i <= n - 1; i++)
    {
        for(auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            long long int c = ed.c;

            if(dis[a] != INF && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    // Negative cycle check
    for(auto ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        long long int c = ed.c;

        if(dis[a] != INF && dis[a] + c < dis[b])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cin >> n >> e;

    while(e--)
    {
        int a, b;
        long long int c;

        cin >> a >> b >> c;

        edge_list.push_back(Edge(a, b, c));
    }

    int src;
    cin >> src;

    bool possible = bellman_ford(src);

    // Negative cycle থাকলে শুধু এটুকুই print
    if(!possible)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int T;
    cin >> T;

    while(T--)
    {
        int destination;
        cin >> destination;

        if(dis[destination] == INF)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dis[destination] << endl;
        }
    }

    return 0;
}