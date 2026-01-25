class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        //taking the reference from the leetcode 153 -->>>
        //my intution is that the index of minimum no. is k
        
        int n=arr.size();
        int s=0, e=n-1;

        int res;
        while(s<=e){
            int mid=(s+e)/2;

            if(arr[mid]> arr[n-1]){
                //it is of part 2
                s=mid+1;
            }

            else{
                //it is of part 1
                res=mid;
                e=mid-1;
            }
        }
        return res;
    }
};
