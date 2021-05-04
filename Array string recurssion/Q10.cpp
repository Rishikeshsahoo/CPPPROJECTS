#include<bits/stdc++.h>
using namespace std;
int kadane(vector<int> v)
{
    int maxsum=INT_MIN,sum=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        if(sum<0)
        sum=0;

        maxsum=max(sum,maxsum);
    }
    return maxsum;
}
int main()
{
    int n=0,k=0;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    int result=kadane(v);
    cout<<"The maximum sum of subarray is: "<<k;

    return 0;
}