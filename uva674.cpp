#include<iostream>
using namespace std;

int main(void)
{
    int coin[]= {1,5,10,25,50};
    int value;
    int dp[7490]={};

    dp[0]=1;

    for(int j=0 ; j<5 ;j++)
    {
        for(int i=coin[j] ; i<=7490 ;i++)
        {
            dp[i]+=dp[i-coin[j]];
        }
    }

    while(cin>>value) cout<<dp[value]<<endl;

    return 0;
}
