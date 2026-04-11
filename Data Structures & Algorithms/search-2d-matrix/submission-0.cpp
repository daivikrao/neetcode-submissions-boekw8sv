class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        if(target < matrix[0][0] || target > matrix[row-1][col-1]){
            return false;
        }

        int i = 0;
        int j = col - 1;

        while(i<=row-1 && j>=0){
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] < target){
                i += 1;
            }else{
                j -= 1;
            }
        }
        return false;
    }
};
