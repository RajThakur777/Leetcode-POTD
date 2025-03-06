class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2);
        int n = grid.size();

        map<int , int> mpp;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                mpp[grid[i][j]]++;
            }
        }

        for(int i=1; i<=n*n; i++){
            if(mpp[i] == 2){
                ans[0] = i;
            }

            if(mpp[i] == 0){
                ans[1] = i;
            }
        }
        return ans;
    }
};