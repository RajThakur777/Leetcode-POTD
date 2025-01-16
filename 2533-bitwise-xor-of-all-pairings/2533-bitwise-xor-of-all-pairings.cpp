class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m % 2 == 0 && n % 2 == 0){
            return 0;
        }
        else if(m % 2 != 0 && n % 2 != 0){
            int xr1 = 0;
            for(int i=0; i<m; i++){
                xr1 ^= nums1[i];
            }

            int xr2 = 0;
            for(int i=0; i<n; i++){
                xr2 ^= nums2[i];
            }

            return (xr1 ^ xr2);
        }
        else if(m % 2 != 0 && n % 2 == 0){
            int xr2 = 0;
            for(int i=0; i<n; i++){
                xr2 ^= nums2[i];
            }
            return xr2;
        }
        else {
            int xr1 = 0;
            for(int i=0; i<m; i++){
                xr1 ^= nums1[i];
            }
            return xr1;
        }
    }
};