// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        
        int n=arr.size();
        int s=0, e=n-1;
        int ans= -1;
        
        while(s<=e){
            int mid=(s+e)/2;
            
            if(arr[mid]>=x){
                ans=mid;
                e=mid-1;
            }
            
            else{
                s=mid+1;
            }
        }
        
        return (ans==-1)?-1:ans;
    }
};