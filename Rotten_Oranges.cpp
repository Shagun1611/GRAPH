#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// int orangesRotting(vector<vector<int>>&grid)
// {
//     int n=grid.size();
        
//     int m=grid[0].size();
        
//     int vis[n][m];
//     queue<pair<pair<int,int>,int>>q;
        
//     int countFresh=0;
        
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(grid[i][j]==2)
//             {
//                 q.push({{i,j},0});
//                 vis[i][j]=2;
//             }
//             else
//             {
//                 vis[i][j]=0;
//             }
                
//             if(grid[i][j]==1)
//             {
//                 countFresh++;
//             }
//         }
//     }
//     int tm=0;
//     int delrow[]={-1,0,0,+1};
//     int delcol[]={0,-1,+1,0};
//     int cnt=0;
//     while(!q.empty())
//     {
//         int r=q.front().first.first;
//         int c=q.front().first.second;
//         int t=q.front().second;
            
//         tm=max(t,tm);
            
//         q.pop();
            
//         for(int i=0;i<4;i++)
//         {
//             int nrow=r+delrow[i];
//             int ncol=c+delcol[i];
                
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0)
//             {
//                 vis[nrow][ncol]=2;
//                 q.push({{nrow,ncol},t+1});
//                 cnt++;
//             }
//         }
            
//     }
//     if(cnt!=countFresh)
//     {
//         return -1;
//     }
        
//     return tm;
    
// }


// If we have to solave the question in better time complexity than we can use this aprroach in which instead of using vis array we can directy modify the original grid
int orangesRotting(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();

    queue<pair<int, int>> q;
        int countFresh = 0;
        
        // Push all initially rotten oranges to the queue
        // and count the fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    countFresh++;
                }
            }
        }
        
        if (countFresh == 0) return 0;  // No fresh oranges, no time required
        
        int tm = 0;
        int delrow[] = {-1, 0, 0, +1};
        int delcol[] = {0, -1, +1, 0};
        
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            
            for (int i = 0; i < size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for (int j = 0; j < 4; j++) {
                    int nrow = r + delrow[j];
                    int ncol = c + delcol[j];
                    
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;  // Mark orange as rotten
                        q.push({nrow, ncol});
                        countFresh--;
                        rotted = true;
                    }
                }
            }
            
            if (rotted) tm++;
        }
        
        return countFresh == 0 ? tm : -1;
}


int main()
{
   
   return 0;
}