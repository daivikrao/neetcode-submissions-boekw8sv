class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(target < matrix[0][0] && target > matrix[m-1][n-1]){
            return false;
        }

        int i = 0;
        int j = n - 1;

        while(i<=m-1 && j>=0){
            if(matrix[i][j] < target){
                i += 1;
            }else if(matrix[i][j] > target){
                j -= 1;
            }else if(matrix[i][j] == target){
                return true;
            }
        }
        return false;
    }
};
