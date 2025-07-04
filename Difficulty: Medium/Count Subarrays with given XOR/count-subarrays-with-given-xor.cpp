class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        
        int n=arr.size();
        int xr=0;
        int cnt=0;
        //create the map
        map<int ,int>mp;
        mp[xr]++; //{0,1}
        
        for(int i=0;i<n;i++){
            xr=xr ^ arr[i];
            
            int x=xr^k;
            
            if(mp.find(x)!=mp.end()){
                //x present hai
                cnt+=mp[x];
            }
            
            //also put xr in map
            mp[xr]++;
        }
        
        return cnt;
    }
};