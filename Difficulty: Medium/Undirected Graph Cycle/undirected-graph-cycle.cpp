class Solution {
  public:
  
    bool isCycleDFS(int u,unordered_map<int,vector<int>>&adj,vector<bool>&visited,int parent){
        
        // if(visited[u]==true) return true;
        
            visited[u]=true;
            
            for(auto v:adj[u]){
                if(v==parent) continue;
                
                if(visited[v]==true) return true;
                
                if(isCycleDFS(v,adj,visited,u)==true) return true; //if at any pt. it return true then ret the true
            }
        
        
        return false;
    }
    
    
    
    
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        //creating the adj list
        unordered_map<int,vector<int>>adj;
        
        for(auto it:edges){
            int v=it[1];
            int u=it[0];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        
        //adj list creation ended
        
        vector<bool>visited(V,false);
        
        //this loop is bcoz the graph can also be disconnected graph
        for(int i=0;i<V;i++){
            if(!visited[i] && isCycleDFS(i,adj,visited,-1)){
                return true;
            }
        }
        
        return false;
    }
};