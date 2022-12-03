#include<bits/stdc++.h>
using namespace std;
void dfs(int node,unordered_map<int, list<int> > &adj, vector<int> &visited, stack<int> &st){
	visited[node]=1;
	for(auto neighbour:adj[node]){
		if(!visited[neighbour]){
			dfs(neighbour,adj,visited,st);
		}
	}
	st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
	unordered_map<int, list<int> >adj;
	vector<int> visited(v,0);
	stack<int> st;
	vector<int> ans;
	for(int i=0;i<e;i++){
		int u = edges[i][0];
		int v = edges[i][1];
		
		adj[u].push_back(v);
	}
	
	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfs(i,adj,visited,st);
		}
	}
	
	while(!st.empty()){
		int top = st.top();
		ans.push_back(top);
		st.pop();
	}
	
	return ans;
	
}