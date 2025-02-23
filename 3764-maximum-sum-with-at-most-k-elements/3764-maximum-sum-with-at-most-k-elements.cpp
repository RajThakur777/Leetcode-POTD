class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<int> ans;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            vector<int> res;
            for(int j=0; j<m; j++){
                res.push_back(grid[i][j]);
            }

            sort(res.rbegin() , res.rend());
            for(int m=0; m<min(limits[i] , k); m++){
                ans.push_back(res[m]);
            }
        }
        sort(ans.begin() , ans.end());

        long long sum = 0;
        int cnt = 0;
        
        for(int i=ans.size()-1; i>=0 && cnt != k; i--){
            sum += ans[i];
            cnt++;
        }
        return sum;
    }
};