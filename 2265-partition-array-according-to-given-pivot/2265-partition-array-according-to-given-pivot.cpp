// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         vector<int> ans;

//         int n = nums.size();

//         for(int i=0; i<n; i++){
//             if(nums[i] < pivot){
//                 ans.push_back(nums[i]);
//             }
//         }

//         for(int i=0; i<n; i++){
//             if(nums[i] == pivot){
//                 ans.push_back(nums[i]);
//             }
//         }

//         for(int i=0; i<n; i++){
//             if(nums[i] > pivot){
//                 ans.push_back(nums[i]);
//             }
//         }
//         return ans;
//     }
// };




class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> ans(n);

        int i = 0;
        int j = n-1;

        int i_ = 0;
        int j_ = n-1;

        while(i < n && j >= 0){
            if(nums[i] < pivot){
                ans[i_] = nums[i];
                i_++;
            }
            if(nums[j] > pivot){
                ans[j_] = nums[j];
                j_--;
            }
            i++;
            j--;
        }
        while(i_ <= j_){
            ans[i_] = pivot;
            i_++;
        }
        return ans;
    }
};