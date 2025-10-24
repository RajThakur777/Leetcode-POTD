// //Brute force:
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
        
//         set<vector<int>> st;

//         for(int i=0; i<n; i++) {
//             for(int j=i+1; j<n; j++) {
//                 for(int k=j+1; k<n; k++) {
//                     if(nums[i] + nums[j] + nums[k] == 0) {
//                         vector<int> temp = {nums[i] , nums[j] , nums[k]};
//                         sort(temp.begin() , temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }

//         vector<vector<int>> ans(st.begin() , st.end());

//         return ans;
//     }
// };





// //Better:
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
        
//         set<vector<int>> st;

//         for(int i=0; i<n; i++) {
//             set<int> st2;
//             for(int j=i+1; j<n; j++) {
//                 int c = - (nums[i] + nums[j]);
//                 if(st2.find(c) != st2.end()) {
//                     vector<int> temp = {nums[i] , nums[j] , c};
//                     sort(temp.begin() , temp.end());
//                     st.insert(temp);
//                 }
//                 else {
//                     st2.insert(nums[j]);
//                 }
//             }
//         }

//         vector<vector<int>> ans(st.begin() , st.end());

//         return ans;
//     }
// };






//Optimal Solution:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {
                    vector<int> temp = {nums[i] , nums[j] , nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};