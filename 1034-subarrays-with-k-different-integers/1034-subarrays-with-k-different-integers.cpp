// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int n = nums.size();

//         int ans = 0;

//         for(int i=0; i<n; i++){
//             unordered_map<int , int> mpp;
//             for(int j=i; j<n; j++){
//                 mpp[nums[j]]++;

//                 if(mpp.size() == k){
//                     ans++;
//                 }
//                 else if(mpp.size() > k){
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };





class Solution {
public:

    int solve(vector<int> &nums , int k){
        int cnt = 0;

        map<int , int> mpp;

        int i = 0;
        for(int j=0; j<nums.size(); j++){
            mpp[nums[j]]++;

            while(mpp.size() > k){
                mpp[nums[i]]--;

                if(mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }

            cnt += (j - i + 1);
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        return solve(nums , k) - solve(nums , k-1);
    }
};