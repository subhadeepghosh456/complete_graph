//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
      void bfs(vector<vector<char>>& grid,vector<vector<int>> &visited,int row,int col)
      {
          visited[row][col]=1;
          queue<pair<int,int>>q;
          
          q.push({row,col});
          
          int n = grid.size();
          int m = grid[0].size();
          
          while(!q.empty())
          {
              int row = q.front().first;
              int col = q.front().second;
              
              q.pop();
              
              for(int delRow=-1; delRow<=1; delRow++){
                  for(int delCol=-1; delCol<=1; delCol++){
                      
                      int nrow = row+delRow;
                      int ncol = col+delCol;
                      
                      if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1')
                      {
                          visited[nrow][ncol] = 1;
                          q.push({nrow,ncol});
                      }
                  }
              }
              
          }
          
      }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends