// kadanes algo -> o(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n=nums.size();
        int maxi=INT_MIN;

        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            maxi=max(sum,maxi);

            if(sum<0) sum=0;
        }

        return maxi;
    }
};


//better approach -> o(n^2)
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {

//         int n=nums.size();
//         int maxi=INT_MIN;

//         for(int i=0;i<n;i++){
//                 int sum=0;
//             for(int j=i;j<n;j++){
//                 // int sum=0;

//                 sum=sum+nums[j];
//                 maxi=max(maxi,sum);
                
//                 // // for the subarrays
//                 // for(int k=i;k<=j;k++){
//                 //     sum=sum+nums[k];
//                 //     maxi=max(sum,maxi);
//                 // }

//             }
//         }

//         return maxi;
//     }
// };


//bruteforce -> O(n^3)

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {

//         int n=nums.size();
//         int maxi=INT_MIN;

//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 int sum=0;
                
//                 // for the subarrays
//                 for(int k=i;k<=j;k++){
//                     sum=sum+nums[k];
//                     maxi=max(sum,maxi);
//                 }

//             }
//         }

//         return maxi;
//     }
// };
