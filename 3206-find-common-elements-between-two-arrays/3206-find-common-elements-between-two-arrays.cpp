class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1;
        for(int i=0; i<nums2.size(); i++) st1.insert(nums2[i]);

        int cnt1 = 0;
        for(int i=0; i<nums1.size(); i++){
            if(st1.find(nums1[i]) != st1.end()){
                cnt1++;
            }
        }

        vector<int> ans;

        set<int> st2;
        for(int i=0; i<nums1.size(); i++) st2.insert(nums1[i]);

        int cnt2 = 0;
        for(int i=0; i<nums2.size(); i++){
            if(st2.find(nums2[i]) != st2.end()){
                cnt2++;
            }
        }

        ans.push_back(cnt1);
        ans.push_back(cnt2);

        return ans;
    }
};