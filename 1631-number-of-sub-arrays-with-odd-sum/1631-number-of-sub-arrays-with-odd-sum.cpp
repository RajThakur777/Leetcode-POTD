// //Brute force:
// class Solution {
// public:
//     int MOD = 1e9 + 7;

//     int numOfSubarrays(vector<int>& arr) {
//         int n = arr.size();

//         int cnt = 0;
//         for(int i=0; i<n; i++){
//             int sum = 0;
//             for(int j=i; j<n; j++){
//                 sum += arr[j];

//                 if(sum % 2 != 0){
//                     cnt++;
//                 }
//             }
//         }
//         return (cnt) % MOD;
//     }
// };




//Optimized Approach:
// class Solution {
// public:
//     int MOD = 1e9 + 7;

//     int numOfSubarrays(vector<int>& arr) {
//         int n = arr.size();

//         map<int , int> mpp;
//         mpp[0] = 1;

//         int sum = 0;
//         int ans = 0;

//         for(int i=0; i<n; i++){
//             sum += arr[i];

//             if(sum % 2 == 0){
//                 ans = (ans + mpp[1]) % MOD;
//             }
//             else {
//                 ans = (ans + mpp[0]) % MOD;
//             }
//             mpp[(sum % 2)]++;
//         }
//         return (ans % MOD);
//     }
// };





//Using prefix sums:
class Solution {
public:
    int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefix(n);
        prefix[0] = arr[0];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }

        int ans = 0;
        int odd = 0;
        int even = 1;

        for(int i=0; i<n; i++){
            if(prefix[i] % 2 == 0){
                ans = (ans + odd) % MOD;
                even++;
            }
            else {
                ans = (ans + even) % MOD;
                odd++;
            }
        }
        return ans % MOD;
    }
};