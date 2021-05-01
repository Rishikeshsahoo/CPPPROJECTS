#include<bits/stdc++.h>
using namespace std;
int combination(int x)
{
    return (x*(x-1))/2;
}
int zerosumsubarray(vector<int> v)
{
    vector<int> preffix;
    int sum=0;
    int final_answer=0;
    for(int i=0;i<v.size();i++)
    {
        preffix.push_back(sum);
        sum+=v[i];
    }
    unordered_map<int,int> umap;
    for(int i=0;i<preffix.size();i++)
    {
        if(umap.find(preffix[i])==umap.end())
        umap[preffix[i]]=1;
        else
        umap[preffix[i]]++;
    }

    for(auto x:umap)
    {
        if(x.second>1)
        {
            final_answer+=combination(x.second);
        }
    }
    return final_answer;
}
int main()
{
    vector<int> v={4,5,-3,1,-3,2,-6,4,11};
    cout<<zerosumsubarray(v);
    return 0;
}