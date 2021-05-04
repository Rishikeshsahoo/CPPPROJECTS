#include<bits/stdc++.h>
using namespace std;
bool isSafe(int **mat,int x,int y,int n);//prototype
bool NQueen(int **mat,int x,int n)
{
    if(x>=n)
    return true;

    for(int i=0;i<n;i++)
    {
        if(isSafe(mat,x,i,n))
        {
            mat[x][i]=1;
            bool ans=NQueen(mat,x+1,n); //recursion
            if(ans)
            return true;
            mat[x][i]=0; //back track
        }
    }
    return false;
}
bool isSafe(int **mat,int x,int y,int n)
{
    /* checks weather position(x,y) is suitable or not 
    according to laws of chess*/
    for(int i=0;i<x;i++)
    {
        if(mat[i][y]==1)
        return false;
    }
    int row=x,col=y;
    while(row>=0 && col>=0)
    {
        if(mat[row][col]==1)
        return false;
        row--;
        col--;
    }
    while(row>=0 && col<n)
    {
        if(mat[row][col]==1)
        return false;
        row--;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int **mat=new int*[n];
    for(int i=0;i<n;i++)
    {
        mat[i]=new int[n];
        for(int j=0;j<n;j++)
        mat[i][j]=0;
    }
    bool k=NQueen(mat,0,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<mat[i][j]<<" . ";
        cout<<endl;
    }
    return 0;
}