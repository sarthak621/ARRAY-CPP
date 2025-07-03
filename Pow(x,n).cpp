class Solution {
public:
   
    double solve(double x, long long n){
        if(n==0) return 1;
        if(n<0){
            n=n*-1;
            x=1/x;
        }

        if(n%2==0){
            //even
            return solve(x*x,n/2);
        }

        return x*solve(x*x,(n-1)/2); //odd
    }

      
    double myPow(double x, int n) {
        return solve(x,n);
    }
};
