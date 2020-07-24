#include<bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2, int n, int m)
{
    int dp[n][m]={0};
    if(s1[0]==s2[0]) dp[0][0]=1;
    for(int i=1;i<n;i++)
    {
        if(s1[i]==s2[0]) dp[i][0]=1;
        else dp[i][0] = dp[i-1][0];
    }

    for(int i=1;i<m;i++)
    {
        if(s1[0]==s2[i]) dp[0][i]=1;
        else dp[0][i] = dp[0][i-1];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(s1[i]==s2[j]) dp[i][j]= 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n-1][m-1]<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        lcs(s1,s2,n,m);
    }
    return 0;
}