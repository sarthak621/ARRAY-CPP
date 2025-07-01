class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        //step1 transpose => //step 2 reverse every row 
        
        //step 1 : transpose
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //step 2: reverse every row
        for(int row=0;row<n;row++){ 
                reverse(matrix[row].begin() , matrix[row].end());
            
        }
    }
};




//bruteforce
// int n=matrix.size();
        
//         //extra 2D matrix
//         vector<vector<int>>ans(n,vector<int>(n,0));

//         for(int row=0;row<n;row++){
//             for(int col=0;col<n;col++){
//                   ans[col][n-row-1]=matrix[row][col];
//             }
//         }

//         return ans;
