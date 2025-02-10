class Solution {
public:

    void helper(int idx , vector<int> &nums , vector<vector<int>> &ans , vector<int> &res){
        if(idx == nums.size()){
            if(find(ans.begin() , ans.end() , res) == ans.end()){
                ans.push_back(res);
            }
            return;
        }

        //pick
        res.push_back(nums[idx]);
        helper(idx+1 , nums , ans , res);
        res.pop_back();

        //not-pick
        helper(idx+1 , nums , ans , res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) { 
        int n = nums.size();

        sort(nums.begin() , nums.end());

        vector<vector<int>> ans;
        vector<int> res;

        helper(0 , nums , ans , res);

        return ans;
    }
};