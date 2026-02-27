// User function Template for C++

class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,bool>mp;
        
        
        
        vector<int>ans;
        
        for(auto it:arr){
            if(mp[it]!=true){
                ans.push_back(it);
                mp[it]=true;
            }
        }
        
        
        
        return ans;
    }
};