class Solution {
  public:
  
    int lowerBound(vector<int>& arr, int n, int target){
        int s=0, e=n-1;
        int ans=-1;
        
        while(s<=e){
            int mid= s+(e-s)/2;
            
            if(arr[mid] >= target){
                ans=mid;
                e=mid-1;
            }
            
            else{
                s=mid+1;
            }
        }
        
        return ans;
    }  
  
    int upperBound(vector<int>& arr, int n, int target){
        int s=0, e=n-1;
        int ans=-1;
        
        while(s<=e){
            int mid= s+(e-s)/2;
            
            if(arr[mid] > target){
                ans=mid;
                e=mid-1;
            }
            
            else{
                s=mid+1;
            }
        }
        
        return ans;
    }
    
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        
        int lb= lowerBound(arr,n,target);
        if(lb==-1 || arr[lb]!= target) return 0;
        
        int ub= upperBound(arr,n,target);
        
        if(ub==-1) { 
             ub=n-1;
             return ub-lb+1;
        }
        
        return ub-lb;

    }
};










//         //brute -> o(n)
        
        // int cnt=0;
        // int n=arr.size();
        
        // for(int i=0;i<n;i++){
        //     if(arr[i]==target) cnt++;
        // }
        
        // return cnt;