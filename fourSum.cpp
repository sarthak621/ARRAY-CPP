//optimal 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue; //bcoz we dont want the duplicacy
            
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1] ) continue;

                int k=j+1;
                int l=n-1;

                while(k<l){ // if k>l then stop
                     long long sum=nums[i];
                     sum+=nums[j];
                     sum+=nums[k];
                     sum+=nums[l];

                     if(sum==target){
                            //means we have founded the quad
                            vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                            ans.push_back(temp);
                            k++, l--;
                            while(k<l && nums[k]==nums[k-1]) k++;;
                            while(k<l && nums[l]==nums[l+1]) l--;


                     }

                     else if(sum>target) l--;
                     else k++;
                }
            }
        }

        return ans;
    }
};





// //hash map 
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         set<vector<int>>st;

//         for(int i=0;i<n;i++){
//             // set<int>hashSet;
//             for(int j=i+1;j<n;j++){
//                 set<long long>hashSet;

//                 for(int k=j+1;k<n;k++){
//                    long long fourth=1LL* target-(1LL* nums[i]+nums[j]+nums[k]);
//                    if(hashSet.find(fourth)!=hashSet.end()){
//                        vector<int>temp={nums[i],nums[j],nums[k],(int)fourth};
//                        sort(temp.begin(),temp.end());
//                        st.insert(temp);
//                    }
                   
//                    //nums[j] ko insert karo map/set me
//                    hashSet.insert(nums[k]); 
//                 }
                
//             }
//         }

//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;
//     }
// };









// //bruteforce //TLE
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         set<vector<int>>st;

//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     for(int l=k+1;l<n;l++){
//                         long long sum=1LL* nums[i]+nums[j]+nums[k]+nums[l];
//                         if(sum==target){
//                             vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
//                             sort(temp.begin(),temp.end());
//                             st.insert(temp);
//                         }
//                     }
//                 }
//             }
//         }

//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;
//     }
// };
