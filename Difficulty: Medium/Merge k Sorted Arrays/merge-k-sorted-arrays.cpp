class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        
        priority_queue<int,vector<int>,greater<int>>pq;  
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push(mat[i][j]);
            }
        }
        
        vector<int>res;
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            res.push_back(top);
        }
        
        return res;
    }
};