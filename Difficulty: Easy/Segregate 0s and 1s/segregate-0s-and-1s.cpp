// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        
        //two ptr-->as it mentioned the rearrange
        int n=arr.size();
        
        int low=0,high=n-1;
        
        while(low<high){
            
            if(arr[low]==0){
                low++;
            }
            
            else if(arr[high]==1){
                high--;
            }
            
            else{
                //swap
                swap(arr[low],arr[high]);
                low++, high--;
            }
        }
        
        
    }
};