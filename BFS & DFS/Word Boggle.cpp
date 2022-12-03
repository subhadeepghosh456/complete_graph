//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:

    bool dfs(vector<vector<char> >& board,string &word,vector<vector<int>>&vis,int index,int i,int j){
        if(index==word.size()){
            return true;
        }
        
        int n = board.size();
        int m = board[0].size();
        
        int dX[]={-1,-1,0,1,1,1,0,-1};
        int dY[]={0,1,1,1,0,-1,-1,-1};
        
        vis[i][j] = 1;
        
        for(int k=0;k<8;k++){
            int newRow = i+dX[k];
            int newCol = j+dY[k];
            
            if(newRow>=0 && newRow<n && newCol>=0 && 
            newCol<m && !vis[newRow][newCol] && board[newRow][newCol]==word[index])
            {
                if(dfs(board,word,vis,index+1,newRow,newCol)==true){
                    return true;
                }
            }
        }
        
        vis[i][j] = 0;
        return false;
        
    }
    

    bool present(vector<vector<char> >& board,string word){
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int index = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[index]){
                    if(dfs(board,word,vis,index+1,i,j)==true){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    
	    vector<string>ans;
	    for(auto it:dictionary){
	        string word = it;
	        if(present(board,word)){
	            ans.push_back(word);
	        }
	    }
	    return ans;
	    // Code here
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends