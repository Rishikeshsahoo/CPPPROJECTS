#include<stdio.h>
int isArmstrong(int n)
{
    int temp=n,sum=0;
    while(n>0)
    {
        sum+=(n%10)*(n%10)*(n%10);
        n=n/10;
    }
    if(sum==temp)
    return 1;

    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int k=isArmstrong(n);
    
    if(k==1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}