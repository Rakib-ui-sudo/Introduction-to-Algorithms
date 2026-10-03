#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int h[100];

        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }

        int mx = INT_MIN;
        int mn = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (h[i] > mx)
            {
                mn = mx;
                mx = h[i];
            }
            else if (h[i] > mn && h[i] != mx)
            {
                mn = h[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (h[i] == mx)
            {
                cout << i << " ";
            }
            
            if (h[i] == mn)
            {
                cout << i<<" " ;
            }
        }
        cout<<endl;
    }

    return 0;
}