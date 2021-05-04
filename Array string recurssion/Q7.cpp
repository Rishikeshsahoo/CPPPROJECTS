#include<bits/stdc++.h>
using namespace std;

int operation(int n)
{
    int result=0;
    while(n>0)
    {
        int d=n%10;
        result+=d*d;
        n=n/10;
    }
    return result;
}
bool checkHappy(unordered_map<int,bool> m,int n)
{
    if(n==1)
    return true;
    if(m.find(n)!=m.end())
    return false;
    m.insert({n,true});
    n=operation(n);
    return checkHappy(m,n);

}
int main()
{
    int *arr=new int[1000000];
    arr={0};
    
    

}