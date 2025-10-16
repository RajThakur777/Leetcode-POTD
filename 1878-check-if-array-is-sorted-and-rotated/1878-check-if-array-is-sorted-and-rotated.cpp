class Solution {
public:
    bool check(vector<int>& nums) {     
        int n = nums.size();

        vector<int> copy = nums;
        sort(copy.begin() , copy.end());

        for(int i=0; i<n; i++) {
            vector<int> ans(n);
            int x = i;
            for(int j=0; j<n; j++) {
                ans[j] = (copy[(j+x) % n]);
            }

            if(ans == nums) return true;
        }
        return false;
    }
};