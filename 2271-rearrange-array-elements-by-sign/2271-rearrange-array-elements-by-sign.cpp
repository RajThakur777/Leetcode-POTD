class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> pos;
        vector<int> neg;

        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                pos.push_back(nums[i]);
            }
            else {
                neg.push_back(nums[i]);
            }
        }

        for(int i=0; i<n/2; i++) {
            ans[2*i] = pos[i];
            ans[2*i+1] = neg[i];
        }
        return ans;
    }
};