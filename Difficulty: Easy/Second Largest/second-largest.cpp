class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        int large=INT_MIN;
        for(int i=0;i<n;i++){
            if(large<arr[i]){
                large=arr[i];
            }
        }
        
        //now we got the largest
        int sec_lar=INT_MIN;
        for(int i=0;i<n;i++){
            if(sec_lar<arr[i] && arr[i]!=large){
                sec_lar=arr[i];
            }
        }
        
        if(sec_lar==INT_MIN) return -1;
        return sec_lar;
    }
};