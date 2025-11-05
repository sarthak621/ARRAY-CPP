class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        return upper_bound(arr.begin(),arr.end(),target)-arr.begin();
    }
};
