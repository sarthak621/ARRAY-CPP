class Solution {
  public:
  
    int no_of_partition(vector<int>& arr, int k,int mid){
        int sum=0;
        int partition_cnt=1;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]+sum<=mid){
                sum+=arr[i];
            }
            else{
                partition_cnt++;
                sum=arr[i];
            }
        }
        
        return partition_cnt;
    }
    
    int minTime(vector<int>& arr, int k) {
        // code here
        
        // just like we do on book allocation problem here too we find max(min)
        int n=arr.size();
        //impossible case
        if(k>n) return -1;
        
        int low= *max_element(arr.begin(),arr.end());
        int high= accumulate(arr.begin(),arr.end(),0);
        int ans=INT_MIN;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(no_of_partition(arr,k,mid)<=k){
                ans=mid;
                high=mid-1;
            }
            
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};