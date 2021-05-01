#include<bits/stdc++.h>
using namespace std;
vector<int> k_closestto_n(vector<int> v,int k,int x)
{
    int sum=0,currsum=0;
    for(int i=0;i<k;i++)
    {           
        currsum+=abs(x-v[i]);
    }
    int pos=0;
    sum=currsum;
    for(int i=1;i<v.size()-k;i++)
    {
        currsum-=abs(x-v[i-1]);
        currsum+=abs(x+v[i+k-1]);
        if(currsum<sum)
        {
            pos=i;
            sum=currsum;
        }
    }
    vector<int> ans;
    for(int i=0;i<k;i++)
    {
        ans.push_back(v[i+pos]);
    }
    return ans;
}
int main()
{
    vector<int> v={1,2,3,4,5,6};
    vector<int> ans;
    ans=k_closestto_n(v,2,3);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}