#include<bits/stdc++.h>
using namespace std;
int maxCandies(vector<int> candies)
{
    int count=0;
    unordered_map<int,int>m;
    for(int i=0;i<candies.size();i++)
    {
        if(m.find(candies[i])==m.end())
        {
            m.insert({candies[i],1});
            count++;
        }
        else
        {
            m[candies[i]]++;
        }
    }
    return min(count,(int)(candies.size()/2));
    
}
int main()
{
    vector<int> v;
    int s=0,k=0;
    cin>>s;
    for(int i=0;i<s;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    cout<<"answer is: "<<maxCandies(v);

    return 0;
}
