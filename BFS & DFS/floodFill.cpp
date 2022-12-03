//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(vector<vector<int>>& image,vector<vector<int>> &ans,int sr,int sc,int iniColor,int newColor)
    {
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=iniColor || ans[sr][sc]==newColor)
        {
            return;
        }
        
        ans[sr][sc] = newColor;
        
        dfs(image,ans,sr,sc+1,iniColor,newColor);
        dfs(image,ans,sr+1,sc,iniColor,newColor);
        dfs(image,ans,sr-1,sc,iniColor,newColor);
        dfs(image,ans,sr,sc-1,iniColor,newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        dfs(image,ans,sr,sc,iniColor,newColor);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends