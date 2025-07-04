class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        map<long long,int>mp;  //map of sum and index
        long long sum=0;
        int maxLen=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum==k){
                maxLen=max(maxLen,i+1);
            }
            
            long long rem=sum-k;
            
            if(mp.find(rem)!=mp.end()){
                //present in the map
                int len=i-mp[rem];
                maxLen=max(maxLen, len);
            }
            
            //what if there are zeroes
            if(mp.find(sum)==mp.end()){
                //not present in the map 
                mp[sum]=i;
            }
        }
        
        return maxLen;
    }
    
};