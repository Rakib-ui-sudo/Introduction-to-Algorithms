#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj_list[n + 1];

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u); 
    }

    int N;
    cin >> N;

    cout << adj_list[N].size() << endl;
    

    return 0;
}