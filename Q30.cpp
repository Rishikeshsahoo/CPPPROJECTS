#include<bits/stdc++.h>
using namespace std;
vector<int> firstLast(vector<int> v,int target)
{
    int start=0,end=v.size()-1,mid;
    int first,last;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(v[mid]==target)
        {
            first=mid;
            end=mid-1;
        }
        else if(v[mid]>target)
        end=mid-1;

        else if(v[mid]<target)
        start=mid+1; 

    }
    start=0;end=v.size()-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(v[mid]==target)
        {
            last=mid;
            start=mid+1;
        }
        else if(v[mid]>target)
        end=mid-1;

        else if(v[mid]<target)
        start=mid+1;

    }
    vector<int> ans={first,last};
    return ans;
}
int main()
{
    vector<int> v={1,1,1,2,2,2,3,3,3,4,5};
    int target=3;
    vector<int> ans=firstLast(v,target);
    cout<<ans[0]<<" "<<ans[1];

    return 0;
}