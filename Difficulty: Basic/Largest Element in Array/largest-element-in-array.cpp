class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int n=arr.size();
        if(n==1) return arr[0];
        sort(arr.begin(),arr.end());
        
        return arr[n-1];
    }
};
