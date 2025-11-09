//bruteforce

class Solution {
  public:
    int minRow(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(); //no. of rows
        int m=mat[0].size(); //no. of cols
        
        int min_ones=INT_MAX;
        int ind=-1;
        
        for(int i=0;i<n;i++){
            int row_ones_count=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    row_ones_count++;
                }
            }
            if(row_ones_count<min_ones){
                min_ones=row_ones_count;
                ind=i;
            }
        }
        
        return ind+1;
    }
};