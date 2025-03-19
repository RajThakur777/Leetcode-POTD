//Recursion:
class Solution {
public:

    bool helper(int i , int j , int turn , vector<int>& nums , int a , int b){
        if(i > j){
            return a >= b;
        }

        if(turn == 0){
            return helper(i+1 , j , !turn , nums , a+nums[i] , b) || helper(i , j-1 , !turn , nums , a+nums[j] , b);
        }
        else {
            return helper(i+1 , j , !turn , nums , a , b+nums[i]) && helper(i , j-1 , !turn , nums , a , b+nums[j]);
        }
    }

    bool predictTheWinner(vector<int>& nums) {  
        int n = nums.size();

        int a = 0;
        int b = 0;

        return helper(0 , n-1 , 0 , nums , a , b);
    }
};