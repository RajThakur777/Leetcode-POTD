// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();

//         long long ans = 0;

//         for(long long i=0; i<n-2; i++){
//             for(long long j=i+1; j<n-1; j++){
//                 for(long long k=j+1; k<n; k++){
//                     ans = max(ans , ((nums[i] - nums[j]) * 1LL * nums[k]));

//                     if(ans < 0) ans = 0;
//                 }
//             }
//         }
//         return ans;
//     }
// };





class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n);
        vector<int> right(n);

        long long ans = 0;

        for(int i=1; i<n; i++){
            left[i] = max(left[i-1] , nums[i-1]);
        }

        for(int i=n-2; i>=0; i--){
            right[i] = max(right[i+1] , nums[i+1]);
        }

        for(int i=1; i<n-1; i++){
            ans = max(ans , (long long) (left[i] - nums[i]) * right[i]);
        }

        return ans;
    }
};