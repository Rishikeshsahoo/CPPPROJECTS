#include<bits/stdc++.h>
using namespace std;
bool isRectangle(vector<int> r1,vector<int> r2)
{
    if(!(r1[2]<=r2[0] || 
        r1[1]>=r2[3] || 
        r1[0]>=r2[2] ||
        r1[3]<=r2[1] ))
    {
        return false;
    }
    return true;
}

int main()
{
    vector<int> r1,r2;
    for(int i=0;i<4;i++)
    {
        cin>>r1[i];
    }
    for(int i=0;i<4;i++)
    {
        cin>>r2[i];
    }
    cout<<endl<<isRectangle(r1,r2);
    return 0;
}
