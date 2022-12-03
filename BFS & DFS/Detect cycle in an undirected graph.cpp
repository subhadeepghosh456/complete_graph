//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int node,int visited[],int parent[],vector<int> adj[])
    {
        visited[node]=1;
        // parent[node]=-1;
        
        for(auto it:adj[node]){
            if(!visited[it]){
                parent[it]=node;
                if(dfs(it,visited,parent,adj)==true){
                    return true;
                }
            }
            else if(it!=parent[node]){
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int visited[V]={0};
        int parent[V]={-1};
        for(int i=0;i<V;i++){
            if(!visited[i]){
                
                if(dfs(i,visited,parent,adj)==true){
                     return true;
                }
                
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends