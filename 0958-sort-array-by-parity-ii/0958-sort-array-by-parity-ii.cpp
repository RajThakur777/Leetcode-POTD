// class Solution {
// public:
//     vector<int> sortArrayByParityII(vector<int>& nums) {
//         int n = nums.size();

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if((nums[i] % 2 != (i % 2)) && (nums[j] % 2 != (j % 2))){
//                     swap(nums[i] , nums[j]);
//                 }
//             }
//         }
//         return nums;
//     }
// };





class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 1;

        while(i < n && j < n){
            if(nums[i] % 2 == 0){
                i += 2;
            }
            else if(nums[j] % 2 != 0){
                j += 2;
            }
            else {
                swap(nums[i] , nums[j]);
            }
        }
        return nums;
    }
};