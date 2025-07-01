
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int st=0; //start
        int end=nums.size()-1;

        while(st<=end){
            if(nums[st]==2){
                swap(nums[st],nums[end]);
                end--;
            }

            else if(nums[st]==0){
                swap(nums[i],nums[st]);
                i++;
                 st++;
            }

            else if(nums[st]==1){
                st++;
            }
        }       
    }
};


// //t.c o(nlogn) { stl} s.c o(logn)
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//     }
// };
