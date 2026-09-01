class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int low = 0;
        int high = cols - 1;

        while (low<=high){
            int mid = (high + low)/2;
            int rowIndex = 0;

            //find the max elem for mid row.
            for (int i = 1; i < rows; i++){
                if (mat[i][mid] > mat[rowIndex][mid]) {
                    rowIndex = i;
                }
            }

            int leftVal = mid-1>=0 ? mat[rowIndex][mid-1] : -1;
            int rightVal = mid+1<cols ? mat[rowIndex][mid+1] : -1;

            if(mat[rowIndex][mid] > leftVal && mat[rowIndex][mid] > rightVal){
                return {rowIndex, mid};
            }
            else if(mat[rowIndex][mid] < leftVal){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return {};
    }
};