//BFS: using the kahn algo

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        unordered_map<int,vector<int>>adj;
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        
        //adjacency list is created
        
        //kahn algo
        
        queue<int>q;
        vector<int>indegree(V,0);
        for(int u=0;u<V;u++){
            for(auto it:adj[u]){
                indegree[it]++;
            }
        }
        
        //indegree of all element is created above 
        
        //check if there is any elment whose indegree is 0, if yes then push into the q
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int>result;
        //applying the bfs
        while(!q.empty()){
            int u=q.front();
            q.pop();
            result.push_back(u);
            
            for(auto it:adj[u]){
                indegree[it]--;
                
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(result.size()==V) return false;
        
        return true;
    }
};






//using dfs , using the two vector visited and inRecursion

// class Solution {
//   public:
  
//     bool dfsCycle(int u,unordered_map<int,vector<int>>&adj,vector<bool>&visited, vector<bool>&inRecursion){
//         visited[u]=true;
//         inRecursion[u]=true;
        
//         for(auto it:adj[u]){
//             if(visited[it]==false && dfsCycle(it,adj,visited,inRecursion)){
//                 return true;
//             }
            
//             else if(inRecursion[it]==true) return true;
//         }
        
//         inRecursion[u]=false;
//         return false;
//     }
    
    
    
   
//     bool isCyclic(int V, vector<vector<int>> &edges) {

//         unordered_map<int,vector<int>>adj;
        
//         for(auto it:edges){
//             int v=it[1];
//             int u=it[0];
//             adj[u].push_back(v);
//         }
        
//         //adj list creAted
        
//         //now, 
//         vector<bool>visited(V,false);
//         vector<bool>inRecursion(V,false);
        
//         for(int i=0;i<V;i++){
//             if(!visited[i] && dfsCycle(i,adj,visited,inRecursion)){
//                 return true;
//             }
//         }
        
//         return false;
//     }
// };