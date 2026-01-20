// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        
        //kadanes algo
        
        int n=a.size();
        
        int bestEnd=a[0];
        int ans=a[0];
        
        for(int i=1;i<n;i++){
            int v1=bestEnd+a[i];
            int v2=a[i];
            
            bestEnd=min(v1,v2);
            
            ans=min(bestEnd,ans);
        }
        return ans;
    }
};
