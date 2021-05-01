#include<bits/stdc++.h>
using namespace std;
void threePtrSort(vector<int> &v)
{
    int l=0,r=v.size()-1,curr=0;
    while(curr<=r)
    {
        if(v[curr]==0)
        {
            swap(v[curr],v[l]);
            l++;
            curr++;
        }
        else if(v[curr]==2)
        {
            swap(v[curr],v[r]);
            r--;
        }
        else
        {
            curr++;
        }
    }
}
int main()
{
    int n,k;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    threePtrSort(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}