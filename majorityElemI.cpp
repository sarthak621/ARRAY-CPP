// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3

//optimal appproach => moore voting algo
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        
        int cnt=0;
        int elem;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                elem=nums[i];
            }

            else if(nums[i]==elem){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        //now we got the elem verify it is majority or not
        int cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==elem){
                cnt1++;
            }
        }

        if(cnt1>(n/2)){
            return elem;
        }

        return -1;
        
    }
};


// //better appproach => map
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         map<int,int>mp;  //elem , freq
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//         }

//         for(auto it:mp){
//             if(it.second> (n/2)) return it.first;
//         }
//         return -1;
        
//     }
// };



// //bruteforce
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         // int cnt=0;
//         for(int i=0;i<n;i++){
//             int cnt=0;
//             for(int j=i;j<n;j++){
//                   if(nums[i]==nums[j]){
//                     cnt++;
//                   }
//             }

//             if(cnt> (n/2)){
//                 return nums[i];
//             }
//         }

//         return -1;
//     }
// };
