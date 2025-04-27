class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = *max_element(nums.begin() , nums.end());

        vector<int> v(maxi+1 , 0);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int d = abs(nums[i] - nums[j]);

                v[d]++;
            }
        }
        for(int i=0; i<maxi+1; i++){
            k -= v[i];

            if(k <= 0) return i;
        }
        return -1;
    }
};