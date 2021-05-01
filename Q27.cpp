#include<bits/stdc++.h>
using namespace std;
int petrolPump(vector<int> p,vector<int> c)
{
    int start=0,net=0,curr=0;
    for(int i=0;i<p.size();i++)
    {
        net+=p[i]-c[i];
        curr+=p[i]-c[i];
        if(curr<0)
        {
            curr=0;
            start=start+1;
        }
    }
    if(net<0) return -1;
    return start; 
}

int main()
{
    vector<int> petrolAvailable={10,20,30,40,50,60};
    vector<int> cost={30,40,50,40,10,20};
    int answer=petrolPump(petrolAvailable,cost);
    cout<<"start with index: "<<answer;
    return 0;
}