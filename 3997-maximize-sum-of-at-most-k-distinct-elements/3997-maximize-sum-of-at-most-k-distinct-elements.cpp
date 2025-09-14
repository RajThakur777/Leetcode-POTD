class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.rbegin() , nums.rend());

        int cnt = k;
        set<int> st;

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(st.find(nums[i]) == st.end()) {
                ans.push_back(nums[i]);
                st.insert(nums[i]);
                cnt--;
            }

            if(cnt == 0) break;
        }
        return ans;
    }
};