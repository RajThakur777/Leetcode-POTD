class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = *max_element(nums.begin() , nums.end());

        if(maxi <= 0) {
            return maxi;
        }

        vector<int> arr;
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                arr.push_back(nums[i]);
            }
        }
        
        int ans = 0;
        set<int> st;

        for(int i=0; i<arr.size(); i++) {
            if(st.find(arr[i]) == st.end()) {
                ans += arr[i];
                st.insert(arr[i]);
            }
        }
        return ans;
    }
};