/*

You are given an array A of size N. The array contains integers and is of even length. The elements of the array 
represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, 
and receives the value of the coin.

You need to determine the maximum possible amouint of money you can win if you go first.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. 
Each testcase contains two lines of input. The first line contains N denoting the size of the array. 
The second line contains N elements of the array.

Output:
For each testcase, in a new line, print the maximum amout.

Constraints:
1 <= T <= 100
2 <= N <= 100
1 <= Ai <= 106

Examples:
Input:
2
4
5 3 7 10
4
8 15 3 7
Output:
15
22

Explanation:
Testcase1: The user collects maximum value as 15(10 + 5)
Testcase2: The user collects maximum value as 22(7 + 15)

*/

#include<bits/stdc++.h>
using namespace std;

void help(int n, vector<int> &v)
{
    int dp[n][n];

    for(int k=0;k<n;k++)
    {
        for(int i=0, j=k; j<n;i++,j++)
        {
            int x = ((i + 2) <= j) ? dp[i + 2][j] : 0; 
            int y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0; 
            int z = (i <= (j - 2)) ? dp[i][j - 2] : 0;

            dp[i][j] = max (v[i] + min(x,y),v[j] + min(y,z));
        }
    }

    cout<<dp[0][n-1]<<endl;
    return;
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
            
        help(n,v);    
    }
    return 0;
}