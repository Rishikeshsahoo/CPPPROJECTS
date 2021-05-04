#include<bits/stdc++.h>
using namespace std;
vector<int> targetZero(int n)
{
    vector<int> v;

    //inserting values from 1 to n/2 and their -ve
    for(int i=0;i<n/2;i++)
    {
        v.push_back(i+1);
        v.push_back(-1*(i+1));
    }
    //if odd add a zero also
    if(n%2!=0)
    v.push_back(0);

    return v;

}
int main()
{
    int n=0;
    cin>>n;
    vector<int> v=targetZero(n);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;

}