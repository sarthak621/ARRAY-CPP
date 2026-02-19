class Solution {
  public:
  
    int func(int n){
        
        int dig=n;
        int rem=0;
        
        while(dig!=0){
            rem+=dig%10;
            dig=dig/10;
        }
        
        return rem;
    }
    
    int sumOfDigits(int n) {
        // code here
        
        return func(n);
    }
};