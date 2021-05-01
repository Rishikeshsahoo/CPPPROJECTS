#include<bits/stdc++.h>
using namespace std;
int knapsack(int val[],int weight[],int n,int W)
{
    if(n==0 || W==0)
    return 0;
    /*if weight of item is more than remaining 
    capacity then don include*/
    if(weight[n-1]>W)
    return knapsack(val,weight,n-1,W);
    /*maximum value will be considered either 
    by taking the element or not taking it*/
    int k=max((knapsack(val,weight,n-1,W-weight[n-1])+val[n-1]),knapsack(val,weight,n-1,W));
    return k;
}
int main()
{
int wt[]={10,20,30,5};
int val[]={100,50,150,500};
int k=knapsack(val,wt,4,50);
cout<<endl<<k;

}