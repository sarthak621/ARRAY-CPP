class Solution {
  public:
    
    int merge(vector<int> &arr,int low,int mid, int high){
        vector<int>temp;
        int left=low;
        int right=mid+1;
        
        int cnt=0; //cnt variable to count the pairs
        
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                //left is high
                temp.push_back(arr[right]);
                right++;
                cnt+=(mid-left)+1;  // 
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        
        return cnt; //
    }
    
    int mergeSort(vector<int> &arr,int low, int high){
        int mid=(low+high)/2;
        
        int cnt=0;
        
        if(low>=high) return cnt;
        
        //divide
        cnt+= mergeSort(arr,low,mid); //
        cnt+= mergeSort(arr,mid+1,high); //
        
        //conquer
        cnt+= merge(arr,low,mid,high); //
        
        return cnt;
    }
    
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int low=0 , high=arr.size()-1;
        return mergeSort(arr,low,high);
    }
};




// class Solution {
//   public:
//     // Function to count inversions in the array.
    
//     //bruteforce---> O(n^2)
//     int inversionCount(vector<int> &arr) {
//         // Your Code Here
        
//         //t.c.->O(n^2)
        
//         int n=arr.size();
//         int cnt=0;
        
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 if(arr[i]>arr[j]) cnt++;
//             }
//         }
        
//         return cnt;
//     }
// };