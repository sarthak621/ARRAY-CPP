class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int res=0;
        
        unordered_map<int,int>mp;
        mp[0]=1;
        int xor_sum=0;
        
        for(int i=0;i<n;i++){
            xor_sum = xor_sum ^ arr[i];
            int ques= xor_sum ^k;
            
            int freq= mp[ques];
            
            res+=freq;
            
            mp[xor_sum]++;
        }
        
        return res;
    }
};