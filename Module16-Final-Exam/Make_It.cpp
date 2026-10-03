#include<bits/stdc++.h>
using namespace std;///submit dibo nah.
const int num = 10000;
int dp[num + 5];

int main()
{
    dp[1]= 1;

    for (int i = 1; i <=num; i++)
    {
        if(dp[i]==1)
        {
            if(i+3 <= num){
                dp[i+3]=1;
            }

            if (i*2<=num)
            {
                dp[i*2] = 1;
            }
            
        }
    }
    

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;

        if (dp[n]==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
        
    }
    return 0;
}