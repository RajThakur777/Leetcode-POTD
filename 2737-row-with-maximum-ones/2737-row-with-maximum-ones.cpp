class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int maxi = 0;
        int idx = 0;
        vector<int> ans;

        for(int i=0; i<m; i++){
            int val = 0;
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){
                    val++;
                }
            }

            if(val > maxi){
                idx = i;
                maxi = val;
            }
        }
        ans.push_back(idx);
        ans.push_back(maxi);
        return ans;
    }
};