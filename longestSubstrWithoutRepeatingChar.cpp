class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>temp(256,-1);
        int maxLen=0;
        int len;
        int l=0 , r=0; //left //right
        while(r<n){
            if(temp[s[r]]!=-1){
                //already present

                //move left
                if(temp[s[r]]>=l){
                    l=temp[s[r]]+1; 
                } 
            }

            len=r-l+1;
            maxLen=max (len,maxLen);

            temp[s[r]]=r; //storing the right index
            r++;
        }

        return maxLen;
    }
};
