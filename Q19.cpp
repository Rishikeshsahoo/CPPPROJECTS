#include<bits/stdc++.h>
using namespace std;
void zoroShift(vector<int> &v)
{
    int ind=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]!=0)
        {
            swap(v[i],v[ind]);
            ind++;
        }
    }
}
int main()
{
    vector<int> v;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    zoroShift(v);
    cout<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
