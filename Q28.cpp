#include<bits/stdc++.h>
using namespace std;
void elementsWithFrequencyTwo(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        int index=abs(v[i]);
        if(v[index-1]<0)
        {
            cout<<index<<" ";
        }
        else if(v[index-1]>0)
        {
            v[index-1]*=-1;
        }
    }
}
int main()
{
    vector<int> v={5,1,5,1,6,3,6};
    elementsWithFrequencyTwo(v);
    return 0;
}