/*Function to find frequency of x
 * x : element whose frequency is to be found
 * arr : input vector
 */
class Solution {
  public:
    int findFrequency(vector<int> arr, int x) {
        // Your code here
        unordered_map<int,int>mp;
        
        for(auto it:arr){
            mp[it]++;
        }
        
        //now we have to find the freq of x
        if(mp.find(x)!=mp.end()){
            //present in the map
            return mp[x];
        }
        return 0;
    }
};