
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int t = 0, l = 0;
        int b = m-1;
        int r = n-1;

        while(l<=r && t<=b){
            for(int i=l; i<=r; i++){
                ans.push_back(matrix[t][i]);
            }
            t++;

            for(int i=t; i<=b; i++){
                ans.push_back(matrix[i][r]);
            }
            r--;

            if(t<=b){
                for(int i=r; i>=l; i--){
                    ans.push_back(matrix[b][i]);
                }
                b--;
            }

            if(l<=r){
                for(int i=b; i>=t; i--){
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }

        return ans;
    }
};
