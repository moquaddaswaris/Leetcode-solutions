class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        long long res = 1;
        row.push_back(1);
        for(int i=0; i<rowIndex; i++){
            res = res*(rowIndex - i);
            res = res/(i+1);

            row.push_back(res);
        }
        
        return row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int n=0; n<numRows; n++){
           ans.push_back(getRow(n));
        }

        return ans;
    }
};