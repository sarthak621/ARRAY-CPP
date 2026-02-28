class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        
        int n1=a.size();
        int n2=b.size();
        
        unordered_map<int,int>mp;
        
        for(auto it:a){
            mp[it]++;
        }
        
        //now we have created the freq of all the elements in a 
        
        //now our task is to find whether the elem that in a is present in b also
        
        for(int i=0;i<n2;i++){
            int freq=mp[b[i]];
            
            if(freq == 0){
                return false;
            }
            
            mp[b[i]]--;
        }
        
        return true;
    }
};