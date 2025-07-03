//optimize

//hypothetically think of 2d as 1d matrix and then try to search on it
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int low=0 , end= (n*m)-1;
        
        int mid=(low+end)/2;
        while(low<=end){
            mid=(low+end)/2;
            int row=mid/m;
            int col=mid%m;

            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) end=mid-1;
            else low=mid+1;
        }
        return false;

    }
};


// //approach 2
// //T.C -> O(n)+log m=O(n)

// class Solution {
// public:

//     bool bs(vector<int>matrix,int target){
//         int low=0, end=matrix.size()-1;
        
//         int col=matrix.size();
//         int mid=(low+end)/2;
//         while(low<=end){
//             mid=(low+end)/2;
//             if(matrix[mid]==target){
//                 return true;
//             }

//             else if(matrix[mid]>target){
//                 end=mid-1;
//             }
//             else{
//                 low=mid+1;
//             }
//         }
//         return false;
//     }

//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         //bruteforce
//         int n=matrix.size(); //row 
//         int m=matrix[0].size(); //col

//         for(int i=0;i<n;i++){
//             if(matrix[i][0]<=target && matrix[i][m-1]>=target){
//                 return bs(matrix[i],target);
//             }
//         }
//         return false;
//     }
// };


// //bruteforce
// //T.C -> O(n*m)

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         //bruteforce
//         int n=matrix.size(); //row 
//         int m=matrix[0].size(); //col

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==target) return true;
//             }
//         }

//         return false;
//     }
// };
