class Solution {
public:

 //merging logic
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int>temp;
        
        int left=low;
        int right=mid+1;
        
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        
        //if any one of the left guy or riight guy get exhausted in that case add the remaining element
        
        while(left<=mid){
            temp.push_back(nums[left]);
                left++;
        }
        
        while(right<=high){
            temp.push_back(nums[right]);
                right++;
        }
        
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }
    
    int countPairs(vector<int>& nums, int low, int mid, int high){
        int right=mid+1;
        int cnt=0;

        for(int i=low;i<=mid;i++){
            while(right<=high && (long long)nums[i]>1LL* 2*nums[right]){
                right++;
            }
            cnt=cnt+(right-(mid+1));
        }

        return cnt;
    }
    
    int mergeSort(vector<int>& nums, int l, int r) {
        // code here
        int low=l;
        int high=r;
        
        int mid=(l+r)/2;
        
        int cnt=0;

        //base case
        if(l>=r) return cnt; 
        
        cnt+= mergeSort(nums,low,mid);
        cnt+= mergeSort(nums,mid+1,high);

        cnt+= countPairs(nums,low,mid,high);
        
        merge(nums,low,mid,high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};




// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         //bruteforce
//         long long n=nums.size();
//         int cnt=0;

//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]>2*nums[j]){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };
