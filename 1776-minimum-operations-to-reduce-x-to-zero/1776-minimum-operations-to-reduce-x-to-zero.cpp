class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(); 

        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }    

        if(total < x) return -1;
        
        int sum = total - x;

        int res = 0;

        int maxi = INT_MIN;

        int i = 0;
        for(int j=0; j<n; j++){
            res += nums[j];

            while(res > sum && i < n){
                res -= nums[i];
                i++;
            }

            if(res == sum){
                maxi = max(maxi , (j - i + 1));
            }
        }
        return (maxi == INT_MIN) ? -1 : n - maxi;
    }
};