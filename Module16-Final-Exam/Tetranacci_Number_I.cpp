#include<bits/stdc++.h>
using namespace std;      // O(N)

long long int dp[1005];

int Tetra(long long int n)
{
    if(n<2)
       return n;
       
    if(n==2)return 1;
    if(n==3)return 2;
    //if(n==4)return 4;
        
     if(dp[n] != -1)
        return dp[n];

      dp[n] = Tetra(n-1) + Tetra(n-2) + Tetra(n-3) + Tetra(n-4); 
    return dp[n];
}


int main()
{
    memset(dp,-1,sizeof(dp));
    long long int n;
    cin >> n;
    cout << Tetra(n);
    return 0;
}