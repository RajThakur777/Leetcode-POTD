class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        vector<vector<int>> prefix(m , vector<int> (n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0){
                    prefix[i][j] = matrix[i][j];
                }
                else if(i != 0 && j == 0){
                    prefix[i][j] = (prefix[i-1][j] ^ matrix[i][j]);
                }
                else if(i == 0 && j > 0){
                    prefix[i][j] = (prefix[i][j-1] ^ matrix[i][j]);
                }
                else {
                    prefix[i][j] = (prefix[i-1][j] ^ prefix[i][j-1] ^ prefix[i-1][j-1] ^ matrix[i][j]);
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans.push_back(prefix[i][j]);
            }
        }

        sort(ans.rbegin() , ans.rend());

        return ans[k-1];
    }
};