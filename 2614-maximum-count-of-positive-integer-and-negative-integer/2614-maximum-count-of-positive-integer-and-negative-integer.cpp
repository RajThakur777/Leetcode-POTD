// class Solution {
// public:
//     int maximumCount(vector<int>& nums) {   
//         int n = nums.size();

//         int pos = 0;
//         int neg = 0;

//         for(int i=0; i<n; i++){
//             if(nums[i] > 0){
//                 pos++;
//             }
//             else if(nums[i] < 0){
//                 neg++;
//             }
//         }
//         return max(pos , neg);
//     }
// };




class Solution {
public:
    int maximumCount(vector<int>& nums) {   
        int n = nums.size();

        int neg = lower_bound(nums.begin() , nums.end() , 0) - nums.begin();

        int pos = nums.end() - upper_bound(nums.begin() , nums.end() , 0);

        return max(pos , neg);
    }
};