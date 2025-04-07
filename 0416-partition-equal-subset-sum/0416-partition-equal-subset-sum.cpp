// //Recrusion:
// class Solution {
// public:

//     bool helper(int idx , vector<int> &nums , int x){
//         if(x == 0) return true;

//         if(idx >= nums.size()) return false;

//         bool take = false;
//         if(nums[idx] <= x){
//             take = helper(idx+1 , nums , x-nums[idx]);
//         }

//         bool not_take = helper(idx+1 , nums , x);

//         return take || not_take;
//     }

//     bool canPartition(vector<int>& nums) { 
//         int n = nums.size();

//         int S = accumulate(nums.begin() , nums.end() , 0);

//         if(S % 2 != 0) return false;

//         int x = (S) / 2;

//         return helper(0 , nums , x); 
//     }
// };





//Memoization:
class Solution {
public:
    int t[201][20001];

    bool helper(int idx , vector<int> &nums , int x){
        if(x == 0) return true;

        if(idx >= nums.size()) return false;

        if(t[idx][x] != -1){
            return t[idx][x];
        }

        bool take = false;
        if(nums[idx] <= x){
            take = helper(idx+1 , nums , x-nums[idx]);
        }

        bool not_take = helper(idx+1 , nums , x);

        return t[idx][x] = take || not_take;
    }

    bool canPartition(vector<int>& nums) { 
        int n = nums.size();

        int S = accumulate(nums.begin() , nums.end() , 0);

        if(S % 2 != 0) return false;

        int x = (S) / 2;

        memset(t , -1 , sizeof(t));

        return helper(0 , nums , x); 
    }
};