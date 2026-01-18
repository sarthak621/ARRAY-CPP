class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        
        //step 1.. sliding window pattern from longest substring with exact k unique
        //step 2 /.... variable window size
        
        //step 3..info 
        
        int n=s.size();
        int low=0,high=0;
        int res=INT_MIN;
        
        unordered_map<char,int>mp;
        
        for(high=0;high<n;high++){
            mp[s[high]]++;
            
            while(mp.size()>k){
                //ye jab tak karenge jab tak info sahi na ho jaye or equal to k na ho jaye 
                mp[s[low]]--;
                
                if(mp[s[low]]==0){
                    mp.erase(s[low]);
                    
                }
                low++;
            }
            
            if(mp.size()==k){
                int len=high-low+1;
                res=max(len,res);
            }
        }
        
        return res==INT_MIN?-1:res;
        
    }
};