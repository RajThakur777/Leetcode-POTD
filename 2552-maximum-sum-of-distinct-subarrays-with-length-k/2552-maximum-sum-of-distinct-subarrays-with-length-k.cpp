class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;

        int i = 0;
        long long sum = 0;

        unordered_set<int> st;
        for(int j=0; j<n; j++){
            while(st.find(nums[j]) != st.end() || st.size() >= k) {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            st.insert(nums[j]);

            if(st.size() == k){
                ans = max(ans , sum);
            }
        }   
        return ans;
    }
};