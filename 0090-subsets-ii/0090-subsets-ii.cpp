class Solution {
public:

    void recursion(vector<int> &nums , int idx , vector<int> &temp , vector<vector<int>> &ans){
        if(idx == nums.size()){
            if(find(ans.begin() , ans.end() , temp) == ans.end()){
                ans.push_back(temp);
            }
            return;
        }

        //pick
        temp.push_back(nums[idx]);
        recursion(nums , idx + 1 , temp , ans);
        temp.pop_back();

        //not-pick
        recursion(nums , idx + 1 , temp , ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) { 
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(nums.begin() , nums.end());
        
        recursion(nums , 0 , temp , ans);

        return ans;  
    }
};