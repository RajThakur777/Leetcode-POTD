class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        long long v1 = *min_element(nums.begin() , nums.end());
        long long v2 = *max_element(nums.begin() , nums.end());

        long long res = v2 - v1;

        return (res * k);
    }
};