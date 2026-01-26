class Solution {
  public:
  
    bool f(vector<int> &stalls, int k, int n,int guess){
        int cows=1; //it is always possible to place 1 cow
        int prev_cow_pos= stalls[0];
        
        for(int i=1;i<n;i++){
            int dist= stalls[i]- prev_cow_pos;
            if(dist < guess) continue; //idhar mat place karo cow ko
            else{
                prev_cow_pos=stalls[i];
                cows++;
            }
            
        }
        
        if(cows >= k) return true;
        return false;
        
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        
        // pattern: binary search
        int n=stalls.size();
        sort(stalls.begin(), stalls.end());
        // k; //cows / gaya
        
        int low=1; 
        int high= stalls[n-1]- stalls[0]; //max distance
        
        int res=-1;
        
        while(low<=high){
            int guess= (low+high)/2;
            
            if( f(stalls,k,n,guess) ){
                //if possible ho cows ko place karna then kardo
                res=guess;
                low=guess+1;
            }
            else{
                high=guess-1;
            }
        }
        
        return res;
    }
};