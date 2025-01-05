//Brute force:
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        int maxi = 2;
        for(int i=0; i<n; i++){
            int prod = nums[i];
            int GCD = nums[i];
            int LCM = nums[i];
            for(int j=i+1; j<n; j++){
                prod *= nums[j];
                GCD = gcd(GCD , nums[j]);
                LCM = lcm(LCM , nums[j]);

                if(prod != LCM * GCD) break;

                maxi = max(maxi , j - i + 1);
            }
        }
        return maxi;
    }
};