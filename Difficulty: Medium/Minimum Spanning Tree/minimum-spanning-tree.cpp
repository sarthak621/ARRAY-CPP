//         | Prim                    | Kruskal                                 |
// | ----------------------- | --------------------------------------- |
// | Uses adjacency list     | Uses **edge list**                      |
// | Uses priority queue     | Uses **sorting**                        |
// | Grows MST from one node | Builds MST by **connecting components** |
// | Needs `inMST[]`         | Needs **Disjoint Set (DSU)**            |

class Solution {
  public:
  
   vector<int>parent;
   vector<int>rank;
        
   int find (int x) {
        if (x == parent[x]) 
            return x;
    
        return parent[x] = find(parent[x]);
    }
    
    void union_karo (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
    
        if (x_parent == y_parent) 
            return;
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        //step1.. to sort in the ascending order according to the weight 
        
        auto comparator=[&](vector<int>&a, vector<int>&b){
            return a[2]<b[2];  //Put edge a before edge b if a’s weight is smaller than b’s weight
        };
        
        sort(edges.begin(),edges.end(),comparator);
        
        //step 2.. initialize dsu
        parent.resize(V);
	    rank.resize(V, 0);
        
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        
        //step3 .. kruskal algo
        int sum=0;
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            if(find(u)!= find(v)){
                union_karo(u,v);
                sum+=wt;
            }
        }
        
        return sum;
        
        
        
    }
};