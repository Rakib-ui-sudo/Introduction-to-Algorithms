#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> adj_list[N];
bool vis[N];
int level[N];

void bfs(int src)
{
   queue<int> q;
   q.push(src);
   vis[src] = true;
   level[src] = 0;

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
            level[child] = level[par] + 1;
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

   for (int i = 0; i < n; i++)
   {
      vis[i]=false;
      level[i]=-1;
   }
   

   int L;
   cin >> L;

   bfs(0);

   vector<int> ans;
   for (int i = 0; i < n; i++)
   {
      if (level[i] == L)
         ans.push_back(i);
   }

    sort(ans.begin(),ans.end(),greater<int>());

   for(int x : ans)
   {
      cout<<x<<" ";
   }


   return 0;
}