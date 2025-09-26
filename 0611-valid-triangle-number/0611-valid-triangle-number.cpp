// //Brute force:
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         int n = nums.size();

//         sort(nums.begin() , nums.end());

//         int cnt = 0;

//         for(int i=0; i<n-2; i++) {
//             for(int j=i+1; j<n-1; j++) {
//                 for(int k=j+1; k<n; k++) {
//                     if(((nums[i] + nums[j]) > nums[k]) && ((nums[j] + nums[k]) > nums[i]) && ((nums[i] + nums[k]) > nums[j])) {
//                         cnt++;
//                     }
//                 }
//             }
//         }
//         return cnt;
//     }
// };





//Using Binary Search:
class Solution {
public:

    int solve(int l , int r , int k , vector<int> &nums) {
        int ans = 0;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(nums[mid] < k) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int cnt = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int res = solve(j+1 , n-1 , nums[i]+nums[j] , nums);

                if(res != 0) {
                    cnt += (res - j);
                }
            }
        }
        return cnt;
    }
};
