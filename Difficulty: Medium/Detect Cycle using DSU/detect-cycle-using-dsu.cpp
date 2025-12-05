class Solution {
  public:
    
    int find(int i,vector<int>&parent,vector<int>&rank){
        
        if(i==parent[i]) return i;
        
        else{
            return parent[i]=find(parent[i],parent,rank); //compression
        }
    }
    
    
    void unionKaro(int u,int v,vector<int>&parent,vector<int>&rank){
        int x_parent= find(u,parent,rank);
        int y_parent= find(v,parent,rank);
        
        if(x_parent==y_parent) return;
        
        else{
            if(rank[x_parent]>rank[y_parent]) parent[y_parent]=x_parent;
            else if(rank[x_parent]<rank[y_parent]) parent[x_parent]=y_parent;
            else{
                parent[y_parent]=x_parent;
                rank[x_parent]+=1;
            }
        }
    }
    
    
  
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>parent(V);
        vector<int>rank(V);
        
        for(int i=0;i<V;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        //dsu
        for(int u=0;u<V;u++){
            for(auto v:adj[u]){
                if(u<v){
                    int parent_u=find(u,parent,rank);
                    int parent_v=find(v,parent,rank);
                    
                    if(parent_u==parent_v){
                        return true;
                    }
                    
                    else{
                        unionKaro(u,v,parent,rank);
                    }
                }
            }
        }
        return false;
    }
};