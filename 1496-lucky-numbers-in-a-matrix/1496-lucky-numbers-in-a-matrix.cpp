class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int ele = matrix[i][j];

                vector<int> row;
                for(int k=0; k<n; k++){
                    row.push_back(matrix[i][k]);
                }

                vector<int> col;
                for(int t=0; t<m; t++){
                    col.push_back(matrix[t][j]);
                }

                sort(row.begin() , row.end());
                sort(col.begin() , col.end());

                if(row[0] == ele && col[col.size() - 1] == ele) {
                    ans.push_back(ele);
                }
            }
        }
        return ans;
    }
};