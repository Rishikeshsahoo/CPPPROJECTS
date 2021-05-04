#include<bits/stdc++.h>
using namespace std;
int builtAlgo(vector<int> v)
{
    int count=1,maxh=v[0];
    for(int i=1;i<v.size();i++)
    {
        if(v[i]>=maxh)
        {
            maxh=v[i];
            count++;
        }
    }
return count;
}
int main()
{
    vector<int> v;
    int x,size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cout<<"result is:"<<builtAlgo(v);

    return 0;
}