class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int v = m + n;

        int ele1 = 0;
        int ele2 = 0;

        int idx1 = (v / 2) - 1;
        int idx2 = (v / 2);

        int i = 0;
        int j = 0;

        int idx = 0;

        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                if(idx == idx1) ele1 = nums1[i];
                if(idx == idx2) ele2 = nums1[i];
                    idx++;
                    i++;
            }
            else {
                if(idx == idx1) ele1 = nums2[j];
                if(idx == idx2) ele2 = nums2[j];
                    idx++;
                    j++;
                }
            }

            while(i < m) {
                if(idx == idx1) ele1 = nums1[i];
                if(idx == idx2) ele2 = nums1[i];
                idx++;
                i++;
            }

            while(j < n) {
                if(idx == idx1) ele1 = nums2[j];
                if(idx == idx2) ele2 = nums2[j];
                idx++;
                j++;
            }

        if(v % 2 == 1) {
            return (double)(ele2);
        }

        return (double)(((double)(ele1) + (double)(ele2)) / 2.0);
    }
};