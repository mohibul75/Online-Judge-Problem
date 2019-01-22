#include<iostream>

using namespace std;

int main(void)
{
    int test;
    cin>>test;

    while(test--)
    {
        int n;
        cin>>n;

        int item[n],cost[n];
        for(int i=0; i<n ; i++) cin>>cost[i]>>item[i];

        int dp[n+2][32];

        for(int i=0 ; i<=n ; i++)
        {
            for(int j=0 ; j<=30 ; j++)
            {
                if (i==0 || j==0)
                    dp[i][j] = 0;
                else if (item[i-1] <= j)
                    dp[i][j] = max(cost[i-1] + dp[i-1][j-item[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];

            }
        }

        int g,sum=0;
        cin>>g;

        for(int i=0; i<g ; i++)
        {
            int cap;
            cin>>cap;

            sum+=dp[n][cap];
        }

        cout<<sum<<endl;

    }

    return 0;
}
