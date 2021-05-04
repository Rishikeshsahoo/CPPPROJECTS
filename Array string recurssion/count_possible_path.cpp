#include<bits/stdc++.h>
using namespace std;
int countPossiblePaths(int start,int end)
{
    if(start==end)
    return 1;
    if(start>end)
    return 0;
    int count=0;
    for(int i=1;i<=6;i++)
    {
        count+=countPossiblePaths(start+i,end);
    }
    return count;
}
int main()
{
    cout<<countPossiblePaths(0,4);
    return 0;
}