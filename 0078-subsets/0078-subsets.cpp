class Solution {
public:

    void helper(int idx , vector<int> &nums , vector<int> &res , vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(res);
            return;
        }

        //pick
        res.push_back(nums[idx]);
        helper(idx+1 , nums , res , ans);
        res.pop_back();

        //not-pick
        helper(idx+1 , nums , res , ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> res;

        helper(0 , nums , res , ans);

        return ans;
    }
};