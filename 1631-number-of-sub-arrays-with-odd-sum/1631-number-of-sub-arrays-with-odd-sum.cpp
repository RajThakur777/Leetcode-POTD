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
class Solution {
public:
    int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        map<int , int> mpp;
        mpp[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            sum += arr[i];

            if(sum % 2 == 0){
                ans = (ans + mpp[1]) % MOD;
            }
            else {
                ans = (ans + mpp[0]) % MOD;
            }
            mpp[(sum % 2)]++;
        }
        return (ans % MOD);
    }
};