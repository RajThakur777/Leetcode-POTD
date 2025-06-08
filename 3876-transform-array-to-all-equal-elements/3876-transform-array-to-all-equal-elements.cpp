class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> c1 , c2;
        c1 = nums;
        c2 = nums;

        bool flag1 = true;
        bool flag2 = true;

        int cnt1 = 0;
        for(int i=0; i<n-1; i++){
            if(c1[i] != 1) {
                c1[i] *= -1;
                c1[i+1] *= -1;
                cnt1++;
            }

            if(cnt1 == k) break;
        }

        int cnt2 = 0;
        for(int i=0; i<n-1; i++){
            if(c2[i] != -1) {
                c2[i] *= -1;
                c2[i+1] *= -1;
                cnt2++;
            }

            if(cnt2 == k) break;
        }

        for(int i=0; i<n-1; i++){
            if(c1[i] != c1[i+1]) {
                flag1 = false;
                 break;
            }
        }

        for(int i=0; i<n-1; i++){
            if(c2[i] != c2[i+1]) {
                flag2 = false;
                 break;
            }
        }

        if(!flag1 && !flag2) return false;
        return true;
    }
};