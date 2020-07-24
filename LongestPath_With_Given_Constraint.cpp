#include<bits/stdc++.h>
using namespace std;

int help(vector<vector<int>> &v,vector<vector<int>> &dp, int i,int j,int n)
{
    if(i>=n || i<0 || j>=n || j<0) return 0;
    if(dp[i][j]!= -1) return 0;

    int x=INT_MIN; int y=INT_MIN; int w=INT_MIN; int z=INT_MIN;

    if(j<n-1 && ((1+v[i][j])==v[i][j+1])) x= 1+ help(v,dp,i,j+1,n);
    if(j>0 && ((1+v[i][j])==v[i][j-1])) y =1+ help(v,dp,i,j-1,n);
    if(i<n-1 && ((1+v[i][j])==v[i+1][j])) w= 1+ help(v,dp,i+1,j,n);
    if(i>0 && ((1+v[i][j])==v[i-1][j])) z =1+ help(v,dp,i-1,j,n);
 
    return max(x,max(y,max(w,max(z,1))));
}

void path(vector<vector<int>> &v,int n)
{
    int result = 1;
    vector<vector<int>> dp(n,vector<int> (n,-1));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dp[i][j]==-1)
            {
                dp[i][j]=help(v,dp,i,j,n);
            }

            result=max(result,dp[i][j]);
        }
    }
    cout<<result<<endl;
}

int main()
{
    int t;
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

        path(v,n);
    }
    return 0;
}