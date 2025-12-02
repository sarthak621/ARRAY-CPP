class Solution {
  public:
  
    
    void dfs(int u,int n, vector<vector<int>>& adj,  vector<bool>&visited, vector<int>&ans){
        if(visited[u]==true) return;
        
        else{
            visited[u]=true;
            ans.push_back(u);
            
            //explore the nbrs
            for(auto it:adj[u]){
                if(!visited[it]){
                    dfs(it,n,adj,visited,ans);
                }
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<bool>visited(n,false);
        
        vector<int>ans;
        
        dfs(0,n,adj,visited,ans);
        
        return ans;
    }
};