class Solution {
public:

    int sumDigits(int num){
        int sum = 0;

        while(num > 0){
            sum += (num % 10);
            num = num / 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]] = i;
        }

        vector<pair<int , int>> p(n);
        for(int i=0; i<n; i++){
            p[i] = make_pair(sumDigits(nums[i]) , nums[i]);
        }

        sort(p.begin() , p.end());

        int cnt = 0;
        for(int i=0; i<n; i++){
            int val = p[i].second;
            int idx = i;
            int Oidx = mpp[val];

            if(idx != Oidx) {
                mpp[nums[idx]] = Oidx;
                mpp[nums[Oidx]] = idx;
                swap(nums[idx] , nums[Oidx]);
                cnt++;
            }
        }
        return cnt;
    }
};