class Solution {
  public:
  
    bool f(vector<int> &arr, int n, int k, int limit){
        int stud=1;
        int page=0;
        
        for(int i=0;i<n;i++){
            
            if(page+arr[i]<=limit){
                page+=arr[i];
            }
            
            else{
                // give it to the next student
                stud++;
                page=arr[i];
            }
        }
        
        if(k<stud) return false;
        else {
            return true;
            
        }
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n<k) return -1; //impossible 
        
        int low= *max_element(arr.begin(), arr.end());
        int high= accumulate(arr.begin(),arr.end(),0);
        
        int res=-1;
        
        while(low<=high){
            int guess=(low+high)/2;
            
            if( f(arr,n,k,guess) ){
                res=guess;
                high=guess-1;
            }
            
            else{
                low=guess+1;
            }
        }
        
        return res;
    }
};