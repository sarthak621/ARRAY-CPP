//hashing
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int>mp; //el,num

        for(int i=0;i<n;i++){
            int elem=nums[i];
            int moreNeeded=target-elem;

            if(mp.find(moreNeeded)!=mp.end()){
                //find in map
                return {mp[moreNeeded],i};
            }

            else{
                mp[elem]=i; //map of this no. is i; //put in the map
            }
        }

        return {-1,-1};
    }
};
