class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        
        vector<int>lps(s.size(),0);
        int pre=0, suff=1;
        
        while(suff<s.size()){
            
            //when match
            if(s[pre]==s[suff]){
                lps[suff]=pre+1;
                
                pre++,suff++;
            }
            
            //not match
            else{
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }
                
                else{
                    pre=lps[pre-1];
                }
            }
        }
        return lps[s.size()-1];
    }
};