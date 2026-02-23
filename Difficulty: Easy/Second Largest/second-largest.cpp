class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int maxi=-1e9;
        int sec_maxi=-1e9;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            if(arr[i]>maxi){
                sec_maxi=maxi;
                maxi=arr[i];
            }
            
            if(arr[i]>sec_maxi && arr[i]!=maxi){
                sec_maxi=arr[i];
            }
        }
        
        if(sec_maxi==-1e9) return -1;
        
        return sec_maxi;
    }
};