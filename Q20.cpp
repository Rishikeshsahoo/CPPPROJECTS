#include<bits/stdc++.h>
using namespace std;
int checkMax(vector<int> v,int n);
vector<int> flip(vector<int> v,int k);
vector<int> pancakeSort(vector<int> v)
{
    for(int i=v.size()-1;i>=0;i--)
    {
        int mi=checkMax(v,i);
        if(mi!=i)
        {
            v=flip(v,mi);
            v=flip(v,i);
        }
    }
    return v;
}
vector<int> flip(vector<int> v,int k)
{
    for(int i=0,j=k ; i<j ; i++,j--)
    {
        swap(v[i],v[j]);
    }
    return v;
}
int checkMax(vector<int> v,int n)
{
    int maxi=INT_MIN,mi;
    for(int i=0;i<=n;i++)
    {
        if(v[i]>maxi)
        {
            maxi=v[i];
            mi=i;
        }
    }
    return mi;
}
int main()
{
    vector<int> v;
    int n=5,p;
    for(int i=0;i<5;i++)
    {
        cin>>p;
        v.push_back(p);
    }
    v= pancakeSort(v);

    for(int i=0;i<5;i++)
    {
        
        cout<<v[i]<<" ";
    }
}