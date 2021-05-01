#include<bits/stdc++.h>
using namespace std;
int firstPositieMissing(vector<int> v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        if(v[i]<=0 || v[i]>n)
        v[i]=v.size()+2;
    }
    for(int i=0;i<n;i++)
    {
        int k=abs(v[i]-1);
        if(v[k]>0 && v[k]<=n)
            v[k]=-1*abs(v[k]);
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]>0)
        return i+1;
    }
    return n+1;
}
int main()
{
    vector<int> v={1,-1,4,5,6};
    cout<<firstPositieMissing(v);
    return 0;
} 