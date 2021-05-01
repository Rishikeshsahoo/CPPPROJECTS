#include<bits/stdc++.h>
using namespace std;
int checkZeros(int n)
{
    int count=0;
    while(n>0)
    {
        n/=5;
        count+=n;
    }
    return count;
}
int main()
{
    int n=0;
    cin>>n;
    int k=checkZeros(n);
    cout<<endl<<k;
}