#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int Tetra[n+1];
    Tetra[0] = 0;
    Tetra[1] = 1;
    Tetra[2] = 1;
    Tetra[3] = 2;
    // Tetra[4] = 4;

    for (int i = 4; i <=n; i++)
    {
        Tetra[i]  = Tetra[i-1] + Tetra[i-2] + Tetra[i-3]+ Tetra[i-4];
    }
    cout<<Tetra[n]<<endl;
    return 0;
}