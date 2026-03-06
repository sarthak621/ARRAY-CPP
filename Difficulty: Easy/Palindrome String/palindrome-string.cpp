class Solution {
  public:
  
    bool f(string& s){
        int n=s.size();
        int low=0;
        int high=n-1;
        
        while(low<high){
            if(s[low]==s[high]){
                low++;
                high--;
            }
            
            else{
                return false;
            }
        }
        return true;
    }
    
    bool isPalindrome(string& s) {
        
        return f(s);
    }
};