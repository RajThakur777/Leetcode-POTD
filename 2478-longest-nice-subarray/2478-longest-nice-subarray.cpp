// class Solution {
// public:
//     int longestNiceSubarray(vector<int>& nums) {   
//         int n = nums.size();

//         int i = 0;
//         int res = 0;

//         int ans = 1;

//         for(int j=0; j<n; j++){
//             while((res & nums[j]) != 0){
//                 res ^= nums[i];
//                 i++;
//             }
//             res |= nums[j];
//             ans = max(ans , j - i + 1);
//         }
//         return ans;
//     }
// };







class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {   
        int n = nums.size();

        int maxLen = 1;

        for(int i=0; i<n; i++){
            int mask = 0;
            for(int j=i; j<n; j++){
                if((mask & nums[j]) != 0){
                    break;
                }

                maxLen = max(maxLen , j - i + 1);
                mask |= nums[j];
            }
        }
        return maxLen;
    }
};










