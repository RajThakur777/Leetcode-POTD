class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        int ans = -1;
        for(int i=0; i<=1e4; i++) {
            if(st.find(i) == st.end()) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};