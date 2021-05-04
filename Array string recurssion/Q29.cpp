#include<bits/stdc++.h>
using namespace std;
int minimumInArray(vector<int> v)
{
    int start=0,end=v.size()-1,mid;
    
    while(start<end)
    {
        //searching minimum element in a rotated vector
        mid=(start+end)/2;
        if(v[start]<v[end])
        return start;

        if(v[mid]<v[mid-1])
        return mid;

        else if(v[mid]>v[end])
        start=mid+1;
        
        else if(v[mid]<v[end])
        end=mid-1;
    }
    return -1;
}
int main()
{
    vector<int> v={5,6,7,2,3,4};
    int smallestElement=minimumInArray(v);
    cout<<v[smallestElement]<<" "<<smallestElement;
    return 0;
}