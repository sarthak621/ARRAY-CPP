class Solution {
  public:
  
  
    void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&visited,stack<int>&st){
        visited[u]=true;
        
        for(auto v:adj[u]){
            if(!visited[v]){
                dfs(v,adj,visited,st);
            }
        }
        
        st.push(u);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        unordered_map<int,vector<int>>adj;
        
        for(auto it:edges){
            int v=it[1];
            int u=it[0];
            adj[u].push_back(v);
        }
        
        //adj list created
        
        vector<bool>visited(V,false);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        
        
        //
        vector<int>ans;
        while(!st.empty()){
            int top=st.top();
            ans.push_back(top);
            st.pop();
        }
        
        return ans;
        
    }
};