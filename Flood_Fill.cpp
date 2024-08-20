#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int ini,int color,int delrow[],int delcol[])
{
    ans[row][col]=color;

    int n=image.size();
    int m=image[0].size();

    for(int i=0;i<4;i++)
    {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];

        if(nrow<n && nrow>=0 && ncol<n && ncol >=0 && image[nrow][ncol]==ini && ans[nrow][ncol]!=color)
        {
            dfs(nrow,ncol,ans,image,ini,color,delrow,delcol);
        }
    }
}

vector<vector<int>> FloodFill(vector<vector<int>>& image,int sr,int sc,int newColor)
{
    int iniColor=image[sr][sc];
    vector<vector<int>> ans=image;

    int delrow[]={-1,0,0,+1};
    int delcol[]={0,-1,+1,0};

    dfs(sr,sc,ans,image,newColor,iniColor,delrow,delcol);

    return ans;
}

int main()
{
   
   return 0;
}