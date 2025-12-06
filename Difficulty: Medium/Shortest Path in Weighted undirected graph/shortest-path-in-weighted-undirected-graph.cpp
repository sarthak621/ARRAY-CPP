class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<pair<int,int>>>adj;
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        
        //adj list is created
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>result(n+1,INT_MAX);
        vector<int>parent(n+1);
        
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        result[1]=0;
        
        pq.push({0,1}); //dist,node
        
        while(!pq.empty()){
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            
            if(dist>result[node]) continue;
            
            for(auto it:adj[node]){
                int it_node=it.first;
                int it_dist=it.second;
                
                if(it_dist+dist < result[it_node]){
                    result[it_node]=it_dist+dist; //update the value;
                    pq.push({result[it_node],it_node});
                    
                    parent[it_node]=node;
                }
            }
        }
       
        
        int destination=n;
        
        // if destination is unreachable return -1
            if(result[destination]==INT_MAX) return {-1};
            
            
        vector<int>path;
        while(parent[destination]!=destination){
            path.push_back(destination);
            destination=parent[destination];
        }
        path.push_back(1);
        
        reverse(path.begin(),path.end());
        
         path.insert(path.begin(), result[n]);
        
        return path;
        
       
        
        
    }
};