class Solution {
public:

    int digitSum(int n){
        int sum = 0;

        while(n > 0){
            sum += (n % 10);
            n = n / 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        map<int , vector<int>> mpp;

        for(int i=0; i<n; i++){
            int num = digitSum(nums[i]);

            mpp[num].push_back(nums[i]);
        }

        int maxi = -1;
        for(auto &it : mpp){
            sort(it.second.begin() , it.second.end());

            if(it.second.size() >= 2){
                maxi = max(maxi , it.second[it.second.size() - 1] + it.second[it.second.size() - 2]);
            }
        }
        return maxi;
    }
};