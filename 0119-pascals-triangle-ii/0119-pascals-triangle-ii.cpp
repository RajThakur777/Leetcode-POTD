class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = 34;
        vector<vector<int>> ans(n);

        ans[0] = {1};
        if (n > 1) {
            ans[1] = {1, 1};
        }

        for (int i = 2; i < n; i++) {
            vector<int> res(i + 1);
            res[0] = 1;
            res[i] = 1;

            for (int j = 1; j < i; j++) {
                res[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans[i] = res;
        }
        return ans[rowIndex];
    }
};