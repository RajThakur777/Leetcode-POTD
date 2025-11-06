class Solution {
public:

    int maxElement(vector<vector<int>> &mat , int mid) {
        int idx = -1;
        int maxi = INT_MIN;

        for(int i=0; i<mat.size(); i++) {
            if(mat[i][mid] > maxi) {
                maxi = mat[i][mid];
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans; 

        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = low + ((high - low) / 2);

            int maxi_idx = maxElement(mat , mid);
            int col = mid;
            int row = maxi_idx;

            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < n) ? mat[row][mid + 1] : -1;

            if(mat[row][mid] > left && mat[row][mid] > right) {
                ans.push_back(row);
                ans.push_back(mid);
                break;
            }
            else if(mat[row][mid] < left) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};