class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();

        map<int , int> mpp;

        for(int i=0; i<n; i++) {
            mpp[(nums[i] % value + value) % value]++;
        }

        int num = 0;

        while(mpp[num % value] > 0){
            mpp[num % value]--;
            num++;
        }
        return num;
    }
};