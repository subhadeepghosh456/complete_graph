//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int visited[N+1][N+1]={0};
	      
	    queue<pair<pair<int,int> ,int>> q;
	    
	    int x = KnightPos[0];
	    int y = KnightPos[1];
	    
	    q.push({{x,y},0});
	    visited[x][y]=1;
	    
	    int delx[] = {2,2,-2,-2,1,-1,1,-1};
	    int dely[] = {1,-1,1,-1,2,2,-2,-2};
	    
	    if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1]) return 0;
	    
	    
	    while(!q.empty()){
	        int frontx = q.front().first.first;
	        int fronty = q.front().first.second;
	        int steps  = q.front().second;
	        
	        q.pop();
	        
	        
	        
	        for(int i=0;i<8;i++){
	            
	            int newX = frontx+ delx[i];
	            int newY = fronty+ dely[i];
	            
	            if(newX==TargetPos[0] && newY==TargetPos[1]){
	                return steps+1;
	            }
	            
	            if( newX>0 && newX<=N && newY>0 && newY<=N && !visited[newX][newY] ){
	                q.push({{newX,newY},steps+1});
	                visited[newX][newY] = 1;
	                
	            }
	            
	            
	        }
	         
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends