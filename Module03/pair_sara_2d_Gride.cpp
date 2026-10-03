#include <bits/stdc++.h>
using namespace std;

char gride[105][105];
bool vis[105][105];

// pair এর জায়গায় দুটি আলাদা array
int dRow[] = {-1, 1, 0, 0};
int dCol[] = {0, 0, -1, 1};

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + dRow[i];
        int cj = sj + dCol[i];
        cout << ci << " " << cj << endl;
    }
}

int main()
{
    int row, col;
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> gride[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;
    dfs(si, sj);

    return 0;
}

/*input
3 4
....
....
....
1 2
*/