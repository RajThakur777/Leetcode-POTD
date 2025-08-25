// //Recursion:
// class Solution {
// public:
    
//     void solve(int idx , vector<int> &nums , vector<int> &res , int prev , vector<int> &temp) {
//         if(idx >= nums.size()) {
//             if(temp.size() > res.size()) {
//                 res = temp;
//             }
//             return;
//         }

//         //take
//         if(prev == -1 || nums[idx] % prev == 0){
//             temp.push_back(nums[idx]);
//             solve(idx+1 , nums , res , nums[idx] , temp);
//             temp.pop_back();
//         }

//         //not_take
//         solve(idx+1 , nums , res , prev , temp);
//     }

//     vector<int> largestDivisibleSubset(vector<int>& nums) {   
//         sort(nums.begin() , nums.end());

//         int n = nums.size();

//         vector<int> res;
//         vector<int> temp;

//         solve(0 , nums , res  ,-1 , temp);  

//         return res;
//     }
// };




//Bottom Up -> Tabulation:
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {   
        sort(nums.begin() , nums.end());

        int n = nums.size();

        vector<int> dp(n , 1);

        vector<int> prev(n , -1);

        int last = 0;
        int maxi = 1;

        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }

                    if(maxi < dp[i]) {
                        maxi = dp[i];
                        last = i;
                    }
                }
            }
        }

        vector<int> res;
        while(last != -1) {
            res.push_back(nums[last]);
            last = prev[last];
        }
        return res;
    }
};