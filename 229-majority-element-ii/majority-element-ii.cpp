//Optimal Solution: Moore Voting Algo
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        int cnt1 = 0;
        int el1 = 0;

        int cnt2 = 0;
        int el2 = 0;

        for(int i=0; i<n; i++) {
            if(cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(el1 == nums[i]) {
                cnt1++;
            }
            else if(el2 == nums[i]) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        int res1 = 0;
        int res2 = 0;

        for(int i=0; i<n; i++) {
            if(el1 == nums[i]) {
                res1++;
            }
            else if(el2 == nums[i]) {
                res2++;
            }
        }

        if(res1 > (n / 3)) {
            ans.push_back(el1);
        }
        if(res2 > (n / 3)) {
            ans.push_back(el2);
        }
        return ans;
    }
};