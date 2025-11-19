class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();

        set<int> st;

        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        int num = original;

        while(st.find(num) != st.end()) {
            num *= 2;
        }
        return num;
    }
};