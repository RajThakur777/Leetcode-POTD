class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        int ans = -1;
        if(k == 1){
            for(auto it : mpp){
                if(it.second == 1){
                    ans = max(ans , it.first);
                }
            }
            return ans;
        }

        if(n == 2 && k == 2){
            if(nums[0] == nums[1]){
                return nums[0];
            }
            else {
                return max(nums[0] , nums[1]);
            }
        }

        if(k == n){
            return *max_element(nums.begin() , nums.end());
        }

        int a = nums[0];
        int b =  nums[n-1];

        if(mpp[a] == 1 && mpp[b] == 1){
            return max(a , b);
        }
        else if(mpp[a] == 1 && mpp[b] > 1){
            return a;
        }
        else if(mpp[a] > 1 && mpp[b] == 1){
            return b;
        }
        return -1;
    }
};