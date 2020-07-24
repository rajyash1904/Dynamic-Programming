/**
 * Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Example:

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.

*/

#include<bits/stdc++.h>
using namespace std;

bool ssp_recursion(vector<int> &v, int n,int sum)
{
    if(sum>0 && n==0) return false;
    if(sum==0) return true;
    if(sum<0) return false;

    return ssp_recursion(v,n-1,sum) || ssp_recursion(v,n-1,sum-v[n-1]);
}

bool ssp_dp(vector<int> &v,int n,int sum)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=false;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<v[i-1])  dp[i][j]=dp[i-1][j];
            if(j>=v[i-1]) dp[i][j]=dp[i-1][j]||dp[i-1][j-v[i-1]];
        }
    }

    return dp[n][sum];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        int sum;
        cin>>sum;
        //cout<<ssp_recursion(v,n,sum)<<endl;
        cout<<ssp_dp(v,n,sum)<<endl;
    }
}