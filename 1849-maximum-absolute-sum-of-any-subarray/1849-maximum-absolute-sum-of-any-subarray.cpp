//brute force:
// class Solution {
// public:
//     int maxAbsoluteSum(vector<int>& nums) {
//         int n = nums.size();

//         int ans = INT_MIN;

//         for(int i=0; i<n; i++){
//             int sum = 0;
//             for(int j=i; j<n; j++){
//                 sum += nums[j];

//                 ans = max(ans , abs(sum));
//             }
//         }
//         return ans;
//     }
// };





class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;

        //Kadan's Algo for maxi sum
        int cs = 0;
        int ms = INT_MIN;

        for(int i=0; i<n; i++){
            cs += nums[i];

            if(cs < 0) cs = 0;

            ms = max(ms , cs);
        }

        //Kadan's Algo for min sum
        int cs1 = 0;
        int ms1 = INT_MAX;

        for(int i=0; i<n; i++){
            cs1 += nums[i];

            if(cs1 > 0) cs1 = 0;

            ms1 = min(ms1 , (cs1));
        }

        return max(ms , abs(ms1));
    }
};