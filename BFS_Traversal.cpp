#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>BFSOfGraph(int n,vector<int>adj[])
{
    int vis[n]={0};
    vis[0]=1; // 0 based indexing graph is used

    vector<int>result;
    queue<int>q;
    q.push(0);

    while(!q.empty())
    {
        int node=q.front();

        q.pop();
        result.push_back(node);

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }

    }
    return result;
}

int main()
{
    cout<<"Enter the number of nodes and edges: ";
    int n,m;
    cin>>n>>m;
    cout<<endl;

    vector<int>adj[n+1];

    cout<<"Enter the Nodes relation: "<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<"Enter the "<<i+1<<" edge between nodes:";
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
        cout<<endl;

    }
    vector<int> result=BFSOfGraph(n,adj);

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
   
   return 0;
}