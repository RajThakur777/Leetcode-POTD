// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();

//         bool flag = false;

//         for(int i=0; i<n; i++){
//             int sum = 0;
//             for(int j=i; j<n; j++){
//                 sum += nums[j];

//                 if((j - i) >= 2 && (sum % k == 0)){
//                     flag = true;
//                     break;
//                 }
//             }
//         }
//         if(flag) return true;

//         return false;
//     }
// };




class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int , int> mpp;
        mpp[0] = -1;

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];

            int rem = sum % k;

            if(mpp.find(rem) != mpp.end()){
                if((i - mpp[rem]) >= 2){
                    return true;
                }
            }
            else {
                mpp[rem] = i;
            }
        }
        return false;
    }
};