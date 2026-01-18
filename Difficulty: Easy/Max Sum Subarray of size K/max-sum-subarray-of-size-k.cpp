class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        
        //step1... pattern: sliding window
        //step 2 ... fixed size k 
        
        //step3 ... current window's information
        int n=arr.size();
        int low=0, high=k-1;
        int sum=0;
        int res=INT_MIN;
        
        for(int i=0;i<=high;i++){
            sum+=arr[i];
        }
        
        //now, moving the window
        
        while(high<n){
            res=max(res,sum);
            
            low++;
            high++;
            
            //new window information
            
            if(high==n) break;
            
            sum=sum-arr[low-1] + arr[high];
        }
        
        return res;
        
    }
};