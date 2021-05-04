#include<bits/stdc++.h>
using namespace std;
bool isSafe(int **mat,int x,int y,int n);
bool ratInMaze(int **mat,int x,int y,int n,int **solarr)
{
    if(x==n-1 && y==n-1)
    {
        solarr[x][y]=1;
        return true;
    }
    if(isSafe(mat,x,y,n))
    {
        solarr[x][y]=1;
        if(ratInMaze(mat,x+1,y,n,solarr)) return true;
        if(ratInMaze(mat,x,y+1,n,solarr)) return true;

        solarr[x][y]=0;
        return false;
    }
    return false;

}
bool isSafe(int **mat,int x,int y,int n)
{
    if(x<n && y<n && mat[x][y]==1)
    return true;
    return false;
}
int main()
{
    int n=5;
    int **mat=new int *[n];
    for(int i=0;i<5;i++)
    {
        mat[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>mat[i][j];
        }
    }

    int **solarr=new int *[n];
    for(int i=0;i<5;i++)
    {
        solarr[i]=new int[n];
        for(int j=0;j<5;j++)
        solarr[i][j]=0;
    }
    ratInMaze(mat,0,0,5,solarr);
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<solarr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}