class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Checking rows
        for(int i=0; i<9; i++){
            vector<int> count(9,0);

            for(int j=0; j<9; j++){
                if (board[i][j] == '.') {
                    continue;
                }

                int idx = board[i][j] - '1';
                count[idx]++;
                if (count[idx] > 1){
                    return false;
                }
            }
        }

        //Checking colums
        for(int j=0; j<9; j++){
            vector<int> count(9,0);

            for(int i=0; i<9; i++){
                if (board[i][j] == '.') {
                    continue;
                }

                int idx = board[i][j] - '1';
                count[idx]++;
                if (count[idx] > 1){
                    return false;
                }
            }
        }

        //Checking each cells
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){

                vector<int> count(9,0);
                for(int k=i; k<i+3; k++){
                    for(int l=j; l<j+3; l++){
                        if(board[k][l] == '.') continue;

                        int idx = board[k][l] - '1';
                        count[idx]++;
                        if(count[idx] > 1){
                            return false;
                        }
                    }
                }

            }
        }
        return true;
    }
};