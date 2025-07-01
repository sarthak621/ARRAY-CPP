class Solution {
public:

    vector<int>generateValues(int row){
        vector<int>values;
        int res=1;
        values.push_back(res);

        for(int col=1;col<row;col++){ //since no. of element in the row is eQual to no of elem in col
            res=res*(row-col);
            res=res/col;
            values.push_back(res);
        }

        return values;
    }

    vector<vector<int>> generate(int numRows) {
        
        //generate n rows

        vector<vector<int>>ans;

        for(int row=1 ; row<=numRows; row++){
            // vector<int>temp;
            ans.push_back( generateValues(row) );
        }

        // ans.push_back(temp);
        return ans;
    }
};
