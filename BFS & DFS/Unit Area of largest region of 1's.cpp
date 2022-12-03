//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int bfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j){
        queue<pair<int,int>>q;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int dX[]={-1,-1,0,1,1,1,0,-1};
        int dY[]={0,1,1,1,0,-1,-1,-1};
        
        vis[i][j]=1;
        int cnt = 0;
        
        q.push({i,j});
        
        while(!q.empty()){
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            cnt++;
            for(int k=0;k<8;k++){
               int nrow = row + dX[k];
               int ncol = col + dY[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    
                    q.push({nrow,ncol});
                }
            }
        }
        return cnt;
    }
    
    
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int maxArea = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1 && vis[i][j]==0){
                    int area = bfs(grid,vis,i,j);
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends