class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans = 0;

        set<int> st;
        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }

        for(int i=1; i<=100000; i++) {
            if(st.find(i) == st.end() && (i % k == 0)) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};