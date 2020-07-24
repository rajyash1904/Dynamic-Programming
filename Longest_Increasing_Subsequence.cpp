#include<bits/stdc++.h>
using namespace std;

void LIS(vector<int> &A, int n)
{
    vector<int> v(n,1);

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
            if(A[i]>A[j] && v[j]+1>v[i])
                v[i]=v[j]+1;
    }

    cout<<*max_element(v.begin(),v.end())<<endl;
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
        vector<int> A(n);
        for(int i=0;i<n;i++)
            cin>>A[i];
        LIS(A,n);    
    }
    return 0;
}