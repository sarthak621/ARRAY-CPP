class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        //firstly convert the edge list into the adj list
        vector<vector<pair<int,int>>> adj(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        //adj list created
        
        //creating a min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>result(V,INT_MAX);
        
        result[src]=0;
        
        pq.push({0,src}); //{dist,node}
        
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            
             if(dist > result[node])
		        continue;
            
            for(auto it:adj[node]){
                //it ka wt and node
                int it_node=it.first;
                int it_wt=it.second;
                
                if(it_wt+dist<result[it_node]){
                    result[it_node]=it_wt+dist;
                    pq.push({it_wt+dist,it_node});
                }
            }
        }
        
        return result;
    }
};