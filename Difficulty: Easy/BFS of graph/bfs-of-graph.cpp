class Solution {
  public:
  
    void bfs(int u,vector<vector<int>> &adj, vector<bool>&visited,  vector<int>&result){
       queue<int>q;
       q.push(u);
       visited[u]=true;
       result.push_back(u);
       
       while(!q.empty()){
           int u=q.front();
           q.pop();
           
           for(auto it: adj[u]){
               if(!visited[it]){
                   q.push(it);
                   visited[it]=true;
                   result.push_back(it);
               }
           }
       }
    }
    
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        //using the queue :)
        
        int n=adj.size();
        vector<bool>visited(n,false);
        
        vector<int>result;
        
        bfs(0,adj,visited,result);
        
        return result;
    }
};