class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        int n=s.size();
        
        //two ptr
        int low=0, high=n-1;
        
        while(low<high){
            if(s[low]==s[high]){
                low++, high--;
            }
            else{
                return false;
            }
        }
        
        return true;
        //a a a--> a    a same low at 1 and high at 1
    }
};