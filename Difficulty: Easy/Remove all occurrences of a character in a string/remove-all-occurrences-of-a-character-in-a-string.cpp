// User function Template for C++
class Solution {
  public:
    // Function to remove all occurrences of the character from the string
    void removeCharacter(string &s, char c) {
        // code here
        int n=s.size();
      
        for(int i=0;i<n;i++){
            if(s[i]==c){
                s.erase(i,1);
                i--;
            }
        }
        
        
    }
};