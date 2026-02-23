class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        vector<vector<int>>ans;
        
        int n=arr.size();
        
        for(auto it:arr){
            mp[it]++;
        }
        
        for(auto it:mp){
            int elem=it.first;
            int fr=it.second;
            
            ans.push_back({elem,fr});
        }
        
        return ans;
    }
};