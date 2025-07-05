//optimal using two pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;

            while(j<k){ //if j>k stop
                 int sum=nums[i]+nums[j]+nums[k];
                 if(sum<0){
                     j++;
                 }

                 else if(sum>0){
                     k--;
                 }

                 else{
                     //we have found up the triplet
                     vector<int>temp={nums[i],nums[j],nums[k]};
                     ans.push_back(temp);
                     j++;
                     k--;
                     while(j<k && nums[j]==nums[j-1]) j++;
                     while(j<k && nums[k]==nums[k+1]) k--;

                 }
            }
        }
        return ans;
    }
};










// //better hashSet //TLE
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         set<vector<int>>st;

//         for(int i=0;i<n;i++){
//             set<int>hashSet;   //Avoids wrong results or duplicates so that we declare it here
                                //we can also use map but here set seems to be simpler bcoz we 
                                // dont have to store the indexes we want values only

//             for(int j=i+1;j<n;j++){
//                 int third=-(nums[i]+nums[j]);
//                 if(hashSet.find(third)!=hashSet.end()){
//                     vector<int>temp={nums[i],nums[j],third};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
                
//                 //nums[j] ko insert karo map/set me
//                 hashSet.insert(nums[j]); 
//             }
//         }

//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;
//     }
// };




// bruteforce    //TLE
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         set<vector<int>>st;

//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                      if(nums[i]+nums[j]+nums[k]==0){
//                         vector<int>temp={nums[i],nums[j],nums[k]};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                      }
//                 }
//             }
//         }

//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;
//     }
// };
