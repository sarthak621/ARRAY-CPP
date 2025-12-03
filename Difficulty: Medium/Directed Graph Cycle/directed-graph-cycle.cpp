class Solution {
  public:
  
    bool dfsCycle(int u,unordered_map<int,vector<int>>&adj,vector<bool>&visited, vector<bool>&inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        
        for(auto it:adj[u]){
            if(visited[it]==false && dfsCycle(it,adj,visited,inRecursion)){
                return true;
            }
            
            else if(inRecursion[it]==true) return true;
        }
        
        inRecursion[u]=false;
        return false;
    }
    
    
    
   
    bool isCyclic(int V, vector<vector<int>> &edges) {

        unordered_map<int,vector<int>>adj;
        
        for(auto it:edges){
            int v=it[1];
            int u=it[0];
            adj[u].push_back(v);
        }
        
        //adj list creAted
        
        //now, 
        vector<bool>visited(V,false);
        vector<bool>inRecursion(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i] && dfsCycle(i,adj,visited,inRecursion)){
                return true;
            }
        }
        
        return false;
    }
};