// class Solution {
// public:
//     long long countBadPairs(vector<int>& nums) {
//         long long cnt = 0;

//         int n =  nums.size();

//         map<int , int> mpp;

//         for(int i=0; i<n; i++){
//             mpp[nums[i] - i]++;
//         }

//         long long total = (n * 1LL * (n - 1)) / 2;

//         for(auto it : mpp){
//             cnt += (it.second * 1LL * (it.second - 1)) / 2;
//         }
//         return total - cnt;
//     }
// };






class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        long long cnt = 0;

        unordered_map<int , int> mpp;

        mpp[nums[0]] = 1;

        for(int i=1; i<n; i++){
            int elementsBefore = i;
            int equalElements = mpp[nums[i] - i];

            cnt += (elementsBefore - equalElements);

            mpp[nums[i] - i]++;
        }
        return cnt;
    }
};