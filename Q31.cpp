#include<bits/stdc++.h>
using namespace std;
int maxProductSubarray(vector<int> v)
{
    int pp=1,np=1,ans=INT_MIN;
    //watch code video for better clarity
    bool haspos=false,haszero=false;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>0)
        {
            haspos=true;
            pp*=v[i];
            if(np!=1)
            np*=v[i];
        }
        else if(v[i]<0)
        {
            int temp=pp;
            pp=max(1,np*v[i]);
            np=temp*v[i];
        }
        else if(v[i]==0)
        {
            haszero=true;
            np=pp=1;
        }
        ans=max(ans,pp);
    }
    //important condition
    if(ans==1)
    {
        if(haspos==true)
        return ans;
        if(haszero==true)
        return 0;
    }

    return ans;
}
int main()
{
    vector<int> v;
    int n,k;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>k;
    //     v.push_back(k);
    // }
    v={-2,4,-5,6,0,5,-5};
    int ans=maxProductSubarray(v);
    cout<<endl<<ans;
    return 0;
}