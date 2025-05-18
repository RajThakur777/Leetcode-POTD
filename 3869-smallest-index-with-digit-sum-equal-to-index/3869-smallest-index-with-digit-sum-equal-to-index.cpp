class Solution {
public:

    int sumDigits(int n){
        int sum = 0;

        while(n > 0){
            sum += (n % 10);
            n = n / 10;
        }
         return sum;
    }
    
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        int idx = INT_MAX;

        for(int i=0; i<n; i++){
            if(sumDigits(nums[i]) == i){
                idx = min(idx , i);
            }
        }
        return idx == INT_MAX ? -1 : idx;
    }
};