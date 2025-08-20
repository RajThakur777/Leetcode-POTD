class Solution {
public:
    void solve(int idx , vector<int> &candidates , int target , vector<vector<int>> &res ,  vector<int> &temp) {
        if(target == 0) {
            res.push_back(temp);
            return;
        }

        if(idx == candidates.size()) return;

        //pick
        if(candidates[idx] <= target) {
            temp.push_back(candidates[idx]);
            solve(idx , candidates , target - candidates[idx] , res , temp);
            temp.pop_back();
        }

        //not_pick:
        solve(idx+1 , candidates , target , res , temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        vector<int> temp;

        solve(0 , candidates , target , res , temp);

        return res;
    }
};