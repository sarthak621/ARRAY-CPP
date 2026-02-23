class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        int mini= 1e9;
        int sec_mini=1e9;
        
        for(int i=0;i<n;i++){
            if(arr[i]<mini){
                sec_mini=mini;
                mini=arr[i];
            }
            
            else if(arr[i]<sec_mini && arr[i]!=mini){
                sec_mini=arr[i];
            }
        }
        
        if(sec_mini==1e9) return {-1};
        
        return {mini,sec_mini};
        
        
    }
};