class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        // Code Here
        
        //pattern: merge intervals 
        
        int n= intervals.size();
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>res; 
        res.push_back(intervals[0]);
        
        for(int i=1;i<n;i++){
            
            if(res.back()[1] >= intervals[i][0]){
                return true;
            }
            
            else{
                res.push_back(intervals[i]);
            }
            
        }
        
        return false;
    }
};