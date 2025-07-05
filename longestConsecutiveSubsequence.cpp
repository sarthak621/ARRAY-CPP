class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        if(n==0) return 0;

        int longest=1;
        int curr_cnt=0;
        int last_small=INT_MIN;

        for(int i=0;i<n;i++){
            if(nums[i]-1==last_small){
                curr_cnt++;
                last_small=nums[i];
            }

            else if(nums[i]!=last_small){
                curr_cnt=1;
                last_small=nums[i];
            }

            else{
                continue;  //when nums[i]==last_small
            }

            longest=max(longest,curr_cnt);
        }

        return longest;
    }
};












// //bruteforce -> O(N^2) * O(N)
// class Solution {
// public:

//     bool linear_search(vector<int>& nums,int x){
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==x){
//                 return true;
//             }
//         }
//         return false;
//     }
//     int longestConsecutive(vector<int>& nums) {
//         // sort(nums.begin(),nums.end());
//         int n=nums.size();
        
//         if(n==0) return 0;

//         int longest=1;
//         for(int i=0;i<n;i++){
//             int cnt=1;
//             int x=nums[i];

//             while(linear_search(nums,x+1)==true){
//                 cnt++;
//                 x=x+1;
//             }

//             longest=max(longest,cnt);
//         }

//         return longest;
//     }
// };
