#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool  bfs(int sr,vector<int>adj[],int vis[])
{
    vis[sr]=1;
    queue<pair<int,int>>q;
    q.push({sr,-1});
    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;

        q.pop();

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,node});
            }
            else if(parent!=it)
            {
                return true;
            }
        }
    }
    return false;
}

bool cycleExists(int n,vector<int>adj[])
{
    int vis[n]={0};

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(bfs(i,adj,vis))
            {
                return true;
            }
        }
    }
    return false;

}

int main()
{
   
   return 0;
}