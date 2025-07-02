class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());

    }
};







        // int size1=nums1.size();
        // int size2=nums2.size();

        // for(int i=size1-1;i>=0;i--){
        //     if(i+1==m) break;

        //     else if(nums1[i]==0){
        //         nums1.pop_back();
        //     }
        //     else{
        //         break;
        //     }
        // }

        // for(int i=size2-1;i>=0;i--){
        //     if(i+1==n) break;

        //     else if(nums2[i]==0){
        //         nums2.pop_back();
        //     }
        //     else{
        //         break;
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     nums1.push_back(nums2[i]);
        // }

        // sort(nums1.begin(),nums1.end());
