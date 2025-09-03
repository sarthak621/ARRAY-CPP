class Solution {
  public:
    int findSubString(string& str) {
        // code here
        set<char>s;
        for(char it:str){
            s.insert(it);
        }
        int len=s.size();
        
        
        int i=0,j=0;
        
        int ans=INT_MAX;
        unordered_map<char,int>mp;
        
        while(j<str.size()){
            mp[str[j]]++;
            
            if(mp.size()>=len){
                //try to reduce size
                while(mp[str[i]]>1){
                    //means freq is more than 1 you can remove
                    mp[str[i]]--;
                    i++;
                }
                
                ans=min(ans,(j-i+1));
            }
            
            j++;
        }
        
        return ans;
    }
};