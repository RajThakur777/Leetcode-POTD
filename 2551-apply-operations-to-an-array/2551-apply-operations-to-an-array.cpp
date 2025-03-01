// class Solution {
// public:
//     vector<int> applyOperations(vector<int>& nums) {
//         int n = nums.size();

//         for(int i=0; i<n-1; i++){
//             if(nums[i] == nums[i+1]){
//                 nums[i] *= 2;
//                 nums[i+1] = 0;
//             }
//         }

//         vector<int> zeroes;
//         for(int i=0; i<n; i++){
//             if(nums[i] == 0){
//                 zeroes.push_back(nums[i]);
//             }
//         }

//         vector<int> ans;
//         for(int i=0; i<n; i++){
//             if(nums[i] != 0){
//                 ans.push_back(nums[i]);
//             }
//         }

//         int cnt = zeroes.size();

//         while(cnt > 0){
//             ans.push_back(0);
//             cnt--;
//         }
//         return ans;
//     }
// };





class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1] && nums[i] != 0){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        int j = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }

        while(j < n){
            nums[j] = 0;
            j++;
        }
        return nums;
    }
};