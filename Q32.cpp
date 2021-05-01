#include<bits/stdc++.h>
using namespace std;
int peakNumber(vector<int> v)
{
    int start=0,end=v.size()-1,mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(start==end)
        return start;
        else if(v[mid]<v[mid+1])
        start=mid+1;
        else 
        end=mid;
    }
    return -1;
}
int main()
{ 
    vector<int> v={1,2,1,4,5,6,7,8,9};
    int n=peakNumber(v);
    cout<<n;
    return 0;
}