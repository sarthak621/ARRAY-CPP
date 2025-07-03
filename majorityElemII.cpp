//optimal -> moore algo

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        
        int elem1=INT_MIN;
        int elem2=INT_MIN;
        
        int cnt1=0, cnt2=0;

        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=elem2){
                cnt1=1;
                elem1=nums[i];
            }

            else if(cnt2==0 && nums[i]!=elem1){
                cnt2=1;
                elem2=nums[i];
            }

            else if(elem1==nums[i]) cnt1++;
            else if(elem2==nums[i]) cnt2++;

            else{
                cnt1-- ,cnt2--;
            }

        }
 
        //verify
         cnt1=0,cnt2=0 ;
        for(int i=0;i<n;i++){
           if(elem1==nums[i]) cnt1++;
           if(elem2==nums[i]) cnt2++;

        }

        int mini= int(n/3)+1;

        vector<int>ans;
        if(cnt1>=mini) ans.push_back(elem1);
        if(cnt2>=mini) ans.push_back(elem2);

        return ans;

    }
};


// // using map
//class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         map<int,int>mp; //elem,freq
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//         }

//         vector<int>ans;
//         for(auto it:mp){
//             if(it.second > (n/3)) ans.push_back(it.first);
//         }

//         return ans;
//     }
// };
