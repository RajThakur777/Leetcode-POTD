class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {   
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m , 0);
        vector<int> col(n , 0);

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for(int i=0; i<m; i++) {
            if(row[i] != 0) {
                for(int k=0; k<n; k++) {
                    matrix[i][k] = 0;
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(col[i] != 0) {
                for(int k=0; k<m; k++) {
                    matrix[k][i] = 0;
                }
            }
        }
    }
};