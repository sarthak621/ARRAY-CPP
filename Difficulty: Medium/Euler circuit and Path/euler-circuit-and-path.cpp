class Solution {
  public:
    
    void dfs(int u, vector<int> adj[], vector<bool>&visited){
        visited[u]=true;
        
        for(auto it:adj[u]){
            if(!visited[it]){
                 dfs(it,adj,visited);
            }
        }
    }
    
    bool isConnected(int V, vector<int> adj[]){
        
        //checking if all non zero degrees nodes are connected or not
        vector<bool>visited(V,false);
        
        //take any node whose degree is not 0 and apply dfs on it
        int nonZeroDegreeNode;
        for(int i=0;i<V;i++){
            if(adj[i].size()!=0){
                nonZeroDegreeNode=i;
                break;
            }
        }
        
        //we have got one node whose degree is not 0
        
        //apply dfs on it
        dfs(nonZeroDegreeNode,adj,visited);
        
        //checking all non zero degree nodes are visited or not
        
        for(int i=0;i<V;i++){
            if(visited[i]==false && adj[i].size()>0){
                return false;
            }
        }
        
        
        return true;
    }
    
    int isEulerCircuit(int V, vector<int> adj[]) {
        // Code here
        
        if(isConnected(V,adj)==false){
            return 0;
        }
        
        int cnt_Odd_Degree=0;
        
        for(int i=0;i<V;i++){
            if(adj[i].size()%2!=0){
                 cnt_Odd_Degree++;
            }
        }
        
        if(cnt_Odd_Degree>2){
            return 0; //none
        }
        
        else if(cnt_Odd_Degree==2){
            return 1; //euler path
        }
        
        else if(cnt_Odd_Degree==0) {
            return 2; //euler ckt
        }
    }
};