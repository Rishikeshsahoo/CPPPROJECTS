#include<bits/stdc++.h>
using namespace std;
// a modification of boyer moore's algorythm
vector<int> boyerMoore(vector<int> v)
{
int val1=v[0],count1=1;
int val2=0,count2=0;
for(int i=0;i<v.size();i++)
{
    if(count1==0)
    val1=v[i];
    else if(count2==0)
    val2=v[i];
    else if(val1==v[i])
    count1++;
    else if(val2==v[i])
    count2++;
    else
    {
        count1--;
        count2--;
    }
}
count1=count2=0;
vector<int> k;
for(int i=0;i<v.size();i++)
{
    if(v[i]==val1)
    count1++;
    else if(v[i]==val2)
    count2++;
}
if(count1>v.size()/3)
k.push_back(val1);
if(count2>v.size()/3)
k.push_back(val2);

return k;
}
int main()
{

}