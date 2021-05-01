#include<bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int> v)
{
    vector<int> left(v.size(),-1),right(v.size(),-1);
    int prol=1,pror=1;
    for(int i=0;i<v.size();i++)
    {
        left[i]=prol;
        prol*=v[i];
        right[v.size()-i-1]=pror;
        pror*=v[v.size()-i-1];
    }
    for(int i=0;i<left.size();i++)
    {
        cout<<left[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<right.size();i++)
    {
        cout<<right[i]<<" ";
    }
    vector<int> ans;
    for(int i=0;i<left.size();i++)
    {
        ans.push_back(left[i]*right[i]);
    }
    return ans;

}
int main()
{
    vector<int> v={1,2,3,4};
    vector<int> ans=productExceptSelf(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}