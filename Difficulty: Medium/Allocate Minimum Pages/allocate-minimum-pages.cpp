class Solution {
  public:
  
    int f(int currentPageCapacity ,vector<int> &arr, int k){
         
         int student=1;
         int pages_student_have=0;
         
         for(int i=0;i<arr.size();i++){
             if(pages_student_have+arr[i]<=currentPageCapacity){
                 pages_student_have+=arr[i];
             }
             else{
                 student++;
                 pages_student_have=arr[i];
             }
         }
         
         return student;
    }
    
    int findPages(vector<int> &arr, int k) {
        
        //impossibble case
        if(k>arr.size()) return -1;
        // code here
        int low= *max_element(arr.begin(),arr.end());
        int high= accumulate(arr.begin(),arr.end(),0);
        
        while(low<=high){
            int mid=(low+high)/2;
            
            int no_of_student= f(mid,arr,k);
            
            if(no_of_student>k) low=mid+1;
            
            else high=mid-1;
        }
        
        return low;
    }
};