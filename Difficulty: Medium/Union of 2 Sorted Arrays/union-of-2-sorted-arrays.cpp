class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        set<int>st;
        
        int n=a.size();
        int m=b.size();
        
        for(int i=0;i<n;i++){
            st.insert(a[i]);
        }
        
        
        for(int j=0;j<m;j++){
            st.insert(b[j]);
        }
        
        //now printing up the set
        vector<int>ans;
        
        for(auto it:st){
            ans.push_back(it);
            
        }
        
        return ans;
    }
};