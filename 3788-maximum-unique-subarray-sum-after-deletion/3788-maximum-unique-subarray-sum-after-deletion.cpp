class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        if(n == 1) return nums[0];

        int pos = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > 0) pos++;
        }

        if(pos == 0){
            vector<int> temp = nums;
            sort(temp.begin() , temp.end());

            return temp[n-1];
        }
        int maxSum = INT_MIN;
        int sum = 0;
        
        for(auto it : mpp){
            if(it.first > 0 && it.second >= 1){
                sum += it.first;
            }

            maxSum = max(maxSum , sum);
        }
        return maxSum;
    }
};