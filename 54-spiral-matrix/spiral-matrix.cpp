class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        int sr = 0;
        int er = m - 1;
        int sc = 0;
        int ec = n - 1;

        while(sr <= er && sc <= ec) {
            //right
            for(int i=sc; i<=ec; i++) {
               ans.push_back(matrix[sr][i]);
            }
            sr++;

            //bottom
            for(int i=sr; i<=er; i++) {
               ans.push_back(matrix[i][ec]);
            }
            ec--;

            if(sr <= er) {
                //left
                for(int i=ec; i>=sc; i--) {
                    ans.push_back(matrix[er][i]);
                }
                er--;
            }

            if(sc <= ec) {
                //top
                for(int i=er; i>=sr; i--) {
                   ans.push_back(matrix[i][sc]);
                }
                sc++;
            }
        }
        return ans;
    }
};