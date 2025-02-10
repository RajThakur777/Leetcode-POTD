class Solution {
public:

    void helper(int idx , vector<int> &candidates , vector<vector<int>> &ans , vector<int> &res , int target){
        if(idx == candidates.size()) return;

        if(target == 0){
            ans.push_back(res);
            return;
        }

        //pick
        if(candidates[idx] <= target){
            res.push_back(candidates[idx]);
            helper(idx , candidates , ans , res , target-candidates[idx]);
            res.pop_back();
        }

        //not-pick
        helper(idx+1 , candidates , ans , res , target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        vector<int> res;

        helper(0 , candidates , ans , res , target);

        return ans;
    }
};