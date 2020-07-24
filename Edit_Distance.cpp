#include<bits/stdc++.h>
using namespace std;

void ED(string s1,string s2,int n, int m)
{
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else if(s1[i-1]!=s2[j-1]) dp[i][j] = 1+ min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            else dp[i][j]=dp[i-1][j-1];
        }
    }

    cout<<dp[n][m]<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n ,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        ED(s1,s2,n,m);
    }
    return 0;
}