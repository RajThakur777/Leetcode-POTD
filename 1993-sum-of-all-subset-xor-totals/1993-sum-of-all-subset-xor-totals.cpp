class Solution {
public:

    void helper(vector<int> &nums , int idx , vector<int> &res , vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(res);
            return;
        }

        //pick
        res.push_back(nums[idx]);
        helper(nums , idx + 1 , res , ans);
        res.pop_back();

        //not_pick
        helper(nums , idx + 1 , res , ans);
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;
        vector<vector<int>> ans;

        helper(nums , 0 , res , ans);

        int sum = 0;

        for(int i=0; i<ans.size(); i++){
            vector<int> temp = ans[i];
            int xr = 0;

            for(int j=0; j<temp.size(); j++){
                xr ^= temp[j];
            }

            sum += xr;
        }
        return sum;
    }
};