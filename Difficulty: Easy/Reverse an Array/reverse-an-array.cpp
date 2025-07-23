class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        vector<int>ans;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            ans.push_back(arr[i]);
        }
        
        arr=ans;
    }
};