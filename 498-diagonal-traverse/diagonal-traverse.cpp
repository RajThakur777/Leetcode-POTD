class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        map<int , vector<int>> mpp;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                mpp[(i+j)].push_back(mat[i][j]);
            }
        }

        vector<int> ans;

        bool flip = 0;
        for(auto it : mpp) {
            if(flip == 0) {
                reverse(it.second.begin() , it.second.end());
            }
            for(auto arr : it.second) {
                ans.push_back(arr);
            }

            flip = !flip;
        }
        return ans;
    }
};