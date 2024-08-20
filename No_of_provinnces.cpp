#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Ths is for when adjency matrix is given :


// void DFS(int i,vector<int>&vis,vector<vector<int>>&adj)
// {
//     vis[i]=1;
//     for(int j=0;j<adj.size();j++)
//     {
//         if(adj[i][j]==1 && !vis[j])
//         {
//             DFS(j,vis,adj);
//         }
//     }
// }

// int NumberOfProvinces(int n,vector<vector<int>>&adj)
// {
//     vector<int>vis(n,0);
//     int count=0;
//     for(int i=0;i<n;i++)
//     {
//         if(!vis[i])
//         {
//             count++;
//             DFS(i,vis,adj);
//         }
//     }
// }

// when we want to convert to adjency list we will do like this:---

void DFS(int node,vector<int>&vis,vector<int>adj[])
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            DFS(it,vis,adj);
        }
    }
}

int NumberOfProvinces(int n,vector<vector<int>>&adj)
{
    vector<int>adjLs[n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]==1 && i!=j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    vector<int>vis(n,0);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            count++;
            DFS(i,vis,adjLs);
        }
    }
}

int main()
{
   
   return 0;
}