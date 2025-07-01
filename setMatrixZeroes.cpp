// LEETCODE 73 Set Matrix Zeroes

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.
// Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     
        int n= matrix.size(); //row 
        int m= matrix[0].size(); //col.
         
         //step 1. traverse first row and first col and check impact
         
         bool isRowImpact=false;
         bool isColImpact=false;

         //row check
         for(int col=0;col<m;col++){
            if(matrix[0][col]==0){
                  isRowImpact=true; 
            }
         }        

         //col check
         for(int row=0;row<n;row++){
            if(matrix[row][0]==0){
                  isColImpact=true; 
            }
         }


         // step 2 : mark the 1st row and 1st col as zero {used as marker}
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
         }

         // step 3: start from excluding 1st row and 1st col
         for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
         }

         // step 4: finally if first row impacted mark all as 0 and if first col is impact mark all as 0

         if(isRowImpact){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
         }

         if(isColImpact){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
         }
    }
};



// bruteforce -> t.c O(m*n*(m+n))  s.c-> o(m*n) {vector declaration}
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n= matrix.size(); //row 
//         int m= matrix[0].size(); //col.
        
//         // bool visited=true;
//         vector<vector<bool>>visited(n,vector<bool>(m,false));
        

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
                
//                 if(matrix[i][j]==0 && !visited[i][j]){
                    
//                     int currRow=i;
//                     int currCol=j;
//                     for(int j=0;j<m;j++){
//                         if(matrix[currRow][j]!=0){
//                         matrix[currRow][j]=0;
//                         visited[currRow][j]=true  ;
//                         }
//                     }
//                     for(int i=0;i<n;i++){
//                         if(matrix[i][currCol]!=0){
//                         matrix[i][currCol]=0;
//                         visited[i][currCol]=true;
//                         }
//                     }
//                   }
                
//             }
//         }
//     }
// };
