class Solution {
  public:
    void relativeSort(vector<int>& a1, vector<int>& a2) {
        // code here
        
        //we will use the map
        int n1=a1.size();
        int n2=a2.size();
        
        unordered_map<int,int>mp;
        for(auto it:a1){
            mp[it]++;
        }
        
        vector<int>ans;
        
        for(int i=0;i<n2;i++){
            int freq=mp[a2[i]];
            
            while(freq){
                ans.push_back(a2[i]);
                freq--;
            }
            
            mp[a2[i]]=0; //after pushing all the element mark that element freq as 0 in map
        }
        
        //for remaining elements in the a1 that are not in the a2.. we need to put in ans in sorted order
        
        int k1=ans.size();
        
        for(int i=0;i<n1;i++){
            if(mp[a1[i]]>0){
                ans.push_back(a1[i]);
            }
        }
        
        sort(ans.begin()+k1,ans.end());
        
        a1=ans;
    }
};
