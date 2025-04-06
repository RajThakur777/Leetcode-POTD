class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums1[i]);
        }

        int ans = INT_MAX;

        for(int i=0; i<nums2.size(); i++){
            if(st.find(nums2[i]) != st.end()){
                ans = min(ans , nums2[i]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};