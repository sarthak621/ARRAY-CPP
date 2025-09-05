class Solution {
  public:
    int minChar(string &s) {
        // code here
        int n=s.size();
        //step 1. s
        string str=s;
        
        //step 2. find reverse of s
        reverse(str.begin(),str.end());
        
        //step 3 .. s+='$'
        s+='$';
        
        //step 4: s+=rev
        s+=str;
        
        //step 5: lps of s
        int m=s.size(); //new length
        
        vector<int>lps(m,0);
        int pre=0, suff=1;
        
        while(suff<s.size()){
            if(s[pre]==s[suff]){
                lps[suff]=pre+1;
                pre++, suff++;
            }
            
            else{
                //not match
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        
        //step 6 : return ans
        return n-lps[m-1];
        
    }
};
