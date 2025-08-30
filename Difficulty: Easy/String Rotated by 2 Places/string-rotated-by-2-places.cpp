class Solution {
  public:
  
    void rotateClockwise(string &s1){
        //rotate by 1 place
        
        //the last place will come to the first
        char c=s1[s1.size()-1];
        
        for(int i=s1.size()-1;i>=1;i--){
            s1[i]=s1[i-1];
        }
        
        s1[0]=c;
    }
    
    void rotateAntiClock(string &s1){
        //rotate anti by 1 palce 
        
        //the first place will goes to end 
        char c=s1[0];
        
        for(int i=0;i<s1.size()-1;i++){
            s1[i]=s1[i+1];
        }
        
        s1[s1.size()-1]=c;
    }
    
    bool isRotated(string& s1, string& s2) {
        // code here
        
        string clockwise=s1, antiClockwise=s1;
        
        rotateClockwise(clockwise);
        rotateClockwise(clockwise);
        
        if(clockwise==s2) return true;
        
        rotateAntiClock(antiClockwise);
        rotateAntiClock(antiClockwise);
        
        if(antiClockwise==s2) return true;
        
        return false;
    }
};
