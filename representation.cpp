#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

// 1. Using matrix:---


// int main()
// {
//     int n,m;
//     cin>>n>>m;

//     int adj[n+1][m+1];
//     for(int i=0;i<m;i++)
//     {
//         int u,v;

//         cin>>u>>v;

//         adj[u][v]=1;
//         adj[v][u]=1;
//     }
//     return 0;
// }

// 2. using the vector adjency vector array:--

// int main()
// {
//     int n,m;
//     cin>>n>>m;

//     vector<int> adj[n+1];

//     for(int i=0;i<m;i++)
//     {
//         int u,v;
//         cin >> u>>v;

//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     return 0;
// }

// for directed graphs we will have directed edges

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u>>v;

        adj[u].push_back(v);  // because in directed graphs we will have edge either from a to b or b to a not both
        // adj[v].push_back(u);
    }
    return 0;
}