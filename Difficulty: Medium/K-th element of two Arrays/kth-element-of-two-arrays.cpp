class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int m=a.size();
        int n=b.size();
        
        if(m>n){
            return kthElement(b,a,k);
        }
        
        int low=max(0,k-n);
        int high=min(m,k);
        
        while(low<=high){
            int Px=(low+high)/2;
            int Py=k-Px;
            
            int x1=(Px==0)?INT_MIN:a[Px-1];
            int x3=(Px==m)?INT_MAX:a[Px];
            
            int x2=(Py==0)?INT_MIN:b[Py-1];
            int x4=(Py==n)?INT_MAX:b[Py];
            
            if(x1<=x4 && x2<=x3){
                //kth element found
                return max(x1,x2);
            }
            
            else if(x1>x4){
                high=Px-1;
            }
            
            else{
                low=Px+1;
            }
        }
        return -1;
    }
};