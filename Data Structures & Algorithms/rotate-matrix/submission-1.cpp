class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<m;i++){
            int s = 0;
            int e = n - 1;

            while(s<=e){
                swap(matrix[i][s],matrix[i][e]);
                s += 1;
                e -= 1;
            }
        }
    }
};
