class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maxi=-1e9;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            if(arr[i]>maxi){
                maxi=arr[i];
            }
        }
        
        return maxi;
    }
};
