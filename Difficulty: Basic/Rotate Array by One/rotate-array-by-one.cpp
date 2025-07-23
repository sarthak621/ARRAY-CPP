// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        // int temp=arr[0];
        
        vector<int>temp(n);
        for(int i=1;i<n;i++){
            temp[i]=arr[i-1];
        }
        
        temp[0]=arr[n-1];
        
        arr=temp;
        
        
        
    }
};