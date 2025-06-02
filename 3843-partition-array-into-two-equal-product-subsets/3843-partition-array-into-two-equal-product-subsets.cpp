class Solution {
public:
    typedef __int128 ll;
    bool solve(int i, vector<int>& nums, ll target, ll prod){
        int n = nums.size();
        if(i >= n || prod > target) return false;
        if(prod == target) return true;
        return solve(i+1, nums, target, prod*nums[i]) || solve(i+1, nums, target, prod);
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll total = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            total *= (ll)nums[i];
        }
        if(total != (ll)target*target) return false;
        return solve(0, nums, target, 1);
    }
};