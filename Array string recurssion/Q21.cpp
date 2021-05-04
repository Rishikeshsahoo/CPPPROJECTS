#include<bits/stdc++.h>
using namespace std;
int rotatedBinSearch(vector<int> v,int target)
{
    int start=0,end=v.size()-1;
    int mid=start+end/2;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(v[mid]==target)
        return mid;
        else if(v[mid]>v[0])
        {
            if(target>v[mid] || target<v[0])
            start=mid+1;
            else end=mid-1;
        }
        else if(v[mid]<v[0])
        {
            if(target>v[end] || target<v[mid])
            end=mid-1;
            else start=mid+1;
        }
    }
    return -1;
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
    int p=rotatedBinSearch(v,4);
    cout<<endl<<"answer is: "<<p;

}