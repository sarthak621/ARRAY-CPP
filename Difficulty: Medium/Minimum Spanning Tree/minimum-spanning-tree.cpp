class Solution {
  public:
  
    typedef pair<int,int>P;
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        //firstly created the adj list....
        
        unordered_map<int,vector<P>>adj;
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        //adj list created
        
        //now, 
        //making the priority queue of wt,node --->> we are not included the parent bcoz ques didnt ask for the parent 
        priority_queue<P,vector<P>,greater<P>>pq; //wt and node
        vector<bool>inMST(V,false);
        int sum=0;
        
        pq.push({0,0}); // wt-0 and node-0
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int wt=p.first;
            int node=p.second;
            
            if(inMST[node]==true) continue; //agar already true hai to continue
            
            inMST[node]=true; //true mark kar do
            sum+=wt;
            
            for(auto it:adj[node]){
                int it_node=it.first;
                int it_wt=it.second;
                
                if(!inMST[it_node]){
                    pq.push({it_wt,it_node});
                }
            }
        }
        
        return sum;
    }
};