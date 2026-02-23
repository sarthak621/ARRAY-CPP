class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        
        int n=arr.size();
        int s=0, e=n-1;
        
        while(s<e){
            swap(arr[s],arr[e]);
            s++, e--;
        }
    }
};