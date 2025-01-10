class Solution {
public:

    void recursion(vector<int> &nums , int idx , vector<int> &temp , vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[idx]);
        recursion(nums , idx + 1 , temp , ans);
        temp.pop_back();

        //not-take
        recursion(nums , idx + 1 , temp , ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) { 
        vector<vector<int>> ans;
        vector<int> temp;

        recursion(nums , 0 , temp , ans);   

        return ans;
    }
};