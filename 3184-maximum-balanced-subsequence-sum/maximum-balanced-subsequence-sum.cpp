// //Recursion:
// class Solution {
// public:

//     long long solve(int idx , int prev , vector<int> &nums) {
//         if(idx >= nums.size()) {
//             return 0;
//         }

//         long long take = LLONG_MIN;
//         long long not_take = LLONG_MIN;

//         if(prev == -1 || nums[idx] - idx >= nums[prev] - prev) {
//             take = nums[idx] + solve(idx+1 , idx , nums);
//         }
//         not_take = solve(idx+1 , prev , nums);

//         return max(take , not_take);
//     }

//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int maxEl = *max_element(begin(nums), end(nums));
//         if(maxEl <= 0) {
//             return maxEl;
//         }
//         return solve(0 , -1 , nums);
//     }
// };




// //Recursion + Memoization:
// class Solution {
// public:
//     unordered_map<string , long long> mp;

//     long long solve(int idx , int prev , vector<int> &nums) {
//         if(idx >= nums.size()) {
//             return 0;
//         }

//         string key = to_string(idx) + "_" + to_string(prev);
//         if(mp.find(key) != mp.end()) {
//             return mp[key];
//         }

//         long long take = LLONG_MIN;
//         long long not_take = LLONG_MIN;

//         if(prev == -1 || nums[idx] - idx >= nums[prev] - prev) {
//             take = nums[idx] + solve(idx+1 , idx , nums);
//         }
//         not_take = solve(idx+1 , prev , nums);

//         return mp[key] = max<long long>(take , not_take);
//     }

//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int maxEl = *max_element(begin(nums), end(nums));
//         if(maxEl <= 0) {
//             return maxEl;
//         }
//         return solve(0 , -1 , nums);
//     }
// };








// //Tabulation:
// class Solution {
// public:
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int n = nums.size();
        
//         int maxEl = *max_element(begin(nums), end(nums));
//         if(maxEl <= 0) {
//             return maxEl;
//         }

//         vector<long long> t(n);
//         for(int i = 0; i<n; i++) {
//             t[i] = nums[i];
//         }

//         long long maxSum = INT_MIN;
//         for(int i = 0; i<n; i++) {

//             for(int j = 0; j<i; j++) {

//                 if(nums[i] - i >= nums[j] - j) {
//                     t[i] = max<long long>(t[i], t[j] + nums[i]);
//                     maxSum = max<long long>(maxSum, t[i]);
//                 }

//             }
//         }

//         return maxSum > maxEl ? maxSum : maxEl;
//     }
// };










class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i); //Find the element just greater than nums[i]-i;

            long long cur_ans = nums[i];

            if(it != mp.begin()) {
                it--;
                cur_ans += (*it).second;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && (*it).second <= cur_ans) {
                 mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};