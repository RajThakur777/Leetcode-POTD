class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int sum = 0;

        int ans = INT_MIN;

        set<int> st;
        for(int j=0; j<n; j++) {         
            while(st.find(nums[j]) != st.end()){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            st.insert(nums[j]);

            ans = max(ans , sum);
        }
        return ans;
    }
};