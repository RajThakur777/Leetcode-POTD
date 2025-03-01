//Backtracking:
class Solution {
public:
    void helper(int idx, vector<int>& res, vector<vector<int>>& ans, int n, vector<bool>& used) {
        if (idx == n) {
            ans.push_back(res);
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;

            if (i % (idx + 1) == 0 || (idx + 1) % i == 0) {
                used[i] = true;
                res.push_back(i);

                helper(idx + 1, res, ans, n, used);

                used[i] = false;
                res.pop_back();
            }
        }
    }

    int countArrangement(int n) {
        vector<int> res;
        vector<vector<int>> ans;
        vector<bool> used(n + 1, false);

        helper(0, res, ans, n, used);

        return ans.size();
    }
};
