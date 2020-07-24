#include<bits/stdc++.h>
using namespace std;

vector<int> ways;
void count_hops(int n)
{
    int m=ways.size();
    if(n<m) cout<<ways[n]<<endl;
    else
    {
        for(int i=m;i<=n;i++)
        {
            int curr= ways[i-3] +ways[i-2] +ways[i-1];
            ways.push_back(curr);
        }
        cout<<ways[n]<<endl;
    }
    
}

int main()
{
    int t;
    cin>>t;
    ways.push_back(1);
    ways.push_back(1);
    ways.push_back(2);
    ways.push_back(4);
    while(t--)
    {
        int n;
        cin>>n;
        count_hops(n);
    }
    return 0;
}