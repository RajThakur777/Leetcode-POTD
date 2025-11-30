class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == 1) return 1;

        if(k == 0) return n;

        sort(nums.begin() , nums.end());

        int ans = 0;

        set<int> st;
        for(int i=0; i<n; i++) {
            st.insert(nums[i]);
        }

        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]]++;
        }

        for(int i=0; i<n; i++) {
            if(st.find(nums[i]) == st.end()) continue;
            
            int num = nums[i];
            st.erase(num);

            int idx = upper_bound(nums.begin() + i , nums.end() , num) - nums.begin();

            if(idx != n) {
                int v = n - idx;

                if(v >= k) {
                    ans += mpp[num];
                }
            }
        }
        return ans;
    }
};