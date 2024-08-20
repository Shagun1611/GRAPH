#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void DFS(int node,vector<int>adj[],int vis[],vector<int>&result)
{
    vis[node]=1;
    result.push_back(node);

    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            vis[it]=1;
            DFS(it,adj,vis,result);
        }
    }
}

vector<int>DFSOfGraph(int n,vector<int>adj[])
{
    int vis[n]={0};
    int start=0;
    vector<int>result;

    DFS(start,adj,vis,result);
    return result;
}
int main()
{
   
   return 0;
}