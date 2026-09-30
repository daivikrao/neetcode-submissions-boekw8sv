class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> box[9];

        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '.'){
                    continue;
                }

                char val = board[i][j];
                int boxIndex = (i/3)*3+(j/3);

                if(rows[i].count(val) || cols[j].count(val) || box[boxIndex].count(val)){
                    return false;
                }

                rows[i].insert(val);
                cols[j].insert(val);
                box[boxIndex].insert(val);
            }
        }
        return true;
    }
};
