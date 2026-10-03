#include <bits/stdc++.h>
using namespace std;

char gride[105][105];
bool vis[105][105];
vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int row, col;

bool valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + mv[i].first;
        int cj = sj + mv[i].second;

        // ১. ইনডেক্স ভ্যালিড কিনা
        // ২. আগে ভিজিট করা হয়েছে কিনা
        // ৩. ঘরটি দেয়াল/বাধা (#) কিনা
        if (valid(ci, cj) && !vis[ci][cj] && gride[ci][cj] != '#')
        {
            dfs(ci, cj);
            // রিকার্শনের নিচে vis[ci][cj] = true দেওয়ার প্রয়োজন নেই
        }
    }
}

int main()
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> gride[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int si, sj;
    cin >> si >> sj;

    // শুরু করার ঘরটি ভ্যালিড এবং চলাচলের যোগ্য কিনা তা চেক করে DFS চালানো নিরাপদ
    if (valid(si, sj) && gride[si][sj] != '#')
    {
        dfs(si, sj);
    }

    return 0;
}