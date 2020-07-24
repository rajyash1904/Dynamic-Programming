#include<bits/stdc++.h>
using namespace std;

void max_path(vector<vector<int>> &v, int n)
{
    int dp[n+1][n+1]={0};
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int curr=0;
            curr =max(dp[i-1][j],dp[i-1][j-1]);
            if(j+1<=n) curr =max(curr,dp[i-1][j+1]);
            dp[i][j] = curr + v[i-1][j-1];
            sum=max(sum,dp[i][j]);
        }
    }
    cout<<sum<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> v(n,vector<int> (n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>v[i][j];
            }
        }
        max_path(v,n);
    }
    return 0;
}