// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        //cswm
        
        vector<int>result(V,1e8);
        
        result[src]=0;
        
        for(int count=1;count<=V-1;count++){
            
            for(auto it:edges){
               int u=it[0];
               int v=it[1];
               int wt=it[2];
               
               if(result[u]!=1e8 && result[u]+wt<result[v]){
                   //update v
                   result[v]=result[u]+wt;
               }
            }
            
        }
        
        
        //relax ho gaya v-1 times,
        //ab cycle detect karne ke liye one  more time relax kar ke dekh lo agar update hota hai toh cycle hai warna cycle nahi hai
        
        for(auto it:edges){
               int u=it[0];
               int v=it[1];
               int wt=it[2];
               
               if(result[u]!=1e8 && result[u]+wt<result[v]){
                   //update v
                   return {-1};
               }
        }
        
        //else return the result
        return result;
        
        
    }
};
