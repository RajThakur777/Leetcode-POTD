class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<int> ans(n);

        sort(nums1.begin() , nums1.end());

        for(int i=0; i<n; i++){
            int val = nums2[i];

            auto it = upper_bound(nums1.begin() , nums1.end() , val);

            if(it == nums1.end()){
                ans[i] = (nums1.front());
                nums1.erase(nums1.begin());
            }
            else                                                                         {
                ans[i] = (*it);
                nums1.erase(it);
            }
        }
        return ans;
    }
};