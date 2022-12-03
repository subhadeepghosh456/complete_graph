#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    void dfs(int node,vector<int>adj[],vector<int>&curr,vector<int>&visited)
    {
        visited[node] = 1;
        for(auto it:adj[node]){
            if(!visited[it]){
                curr.push_back(it);
                dfs(it,adj,curr,visited);
            }
        }       
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans;
        
        vector<int>adj[n];

        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<n;i++){ 
            vector<int>curr;
            vector<int>visited(n,0);
            dfs(i,adj,curr,visited);
            sort(curr.begin(),curr.end());
            ans.push_back(curr);
        }

        return ans;

    }
};