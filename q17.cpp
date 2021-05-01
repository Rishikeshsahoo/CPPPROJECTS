#include<bits/stdc++.h>
using namespace std;
bool check(int a[],int n,int m)
{
    if(m==0 && a[m+1]!=a[m]) return true;
    if(m==n-1 && a[m]!=a[m-1]) return true;
    if(a[m]!=a[m-1] && a[m]!=a[m+1]) return true;
    return false;    
}
int lonelyInteger(int arr[],int n)
{
    int start=0,end=n-1;
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(check(arr,n,mid)) return arr[mid];
        
        if(arr[mid]==arr[mid-1])
        {
            if((mid-1)%2==0) start=mid+1;
            else end=mid-1; 
        }
        else if(arr[mid]==arr[mid+1])
        {
            if((mid)%2==0) start=mid+1;
            else end=mid-1;
        }

    }
    return -1;
}
int main()
{
    int arr[]={1,1,2,2,3,3,4,4,5};
    cout<<endl<<lonelyInteger(arr,10);

}