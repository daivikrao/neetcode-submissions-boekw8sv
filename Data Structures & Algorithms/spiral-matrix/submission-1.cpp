class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        int sr = 0;
        int sc = 0;
        int er = matrix.size()-1;
        int ec = matrix[0].size()-1;
        int count = 0;
        vector<int> ans;

        while(sr<=er && sc<=ec){
            for(int i=sc;i<=ec;i++){
                ans.push_back(matrix[sr][i]);
                count += 1;
            }
            if(count == m*n){
                return ans;
            }
            sr += 1;

            for(int i=sr;i<=er;i++){
                ans.push_back(matrix[i][ec]);
                count += 1;
            }
            if(count == m*n){
                return ans;
            }
            ec -= 1;

            for(int i=ec;i>=sc;i--){
                ans.push_back(matrix[er][i]);
                count += 1;
            }
            if(count == m*n){
                return ans;
            }
            er -= 1;

            for(int i=er;i>=sr;i--){
                ans.push_back(matrix[i][sc]);
                count += 1;
            }
            if(count == m*n){
                return ans;
            }
            sc += 1;
        }
        return ans;
    }
};
