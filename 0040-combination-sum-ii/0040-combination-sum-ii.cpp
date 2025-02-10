class Solution {
public:

    void helper(int idx , vector<int> &candidates , vector<vector<int>> &ans , vector<int> &res , int target){
        if(target == 0){
            if(find(ans.begin() , ans.end() , res) == ans.end()) {
                ans.push_back(res);
            }
            return;
        }

        if (idx == candidates.size()) return;

        //pick
        if(candidates[idx] <= target){
            res.push_back(candidates[idx]);
            helper(idx + 1 , candidates , ans , res , target - candidates[idx]);
            res.pop_back();
        }

        while (idx + 1 < candidates.size() && candidates[idx] == candidates[idx + 1]) {
            idx++;
        }

        //not-pick
        helper(idx + 1 , candidates , ans , res , target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;

        sort(candidates.begin() , candidates.end());

        helper(0 , candidates , ans , res , target);

        return ans;
    }
};