//Brute force:
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ans;
//         int n = nums.size();

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if(nums[i] + nums[j] == target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                 }
//             }
//         }
//         return ans;
//     }
// };







//Better Approach:
// class Solution {
//  public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();

//         sort(nums.begin() , nums.end());

//         int i = 0;
//         int j = n-1;

//         vector<int> ans;

//         while(i < j){
//             int sum = nums[i] + nums[j];

//             if(sum == target){
//                 ans.push_back(i);
//                 ans.push_back(j);
//             }
//             else if(sum > target){
//                 j--;
//             }
//             else {
//                 i++;
//             }
//         }
//         return ans;
//     }
// };






//Optimal Approach:
class Solution {
 public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mpp;

        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            int first = nums[i];
            int second = target - first;

            if(mpp.find(second) != mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[second]);
                break;
            }

            mpp[first] = i;
        }
        return ans;
    }
};