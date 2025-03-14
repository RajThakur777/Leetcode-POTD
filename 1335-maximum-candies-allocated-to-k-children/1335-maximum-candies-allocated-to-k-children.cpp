class Solution {
public:

    bool isPossible(int mid , vector<int>& candies , long long k) {
        long long cnt = 0;

        for(int i=0; i<candies.size(); i++){
            cnt += (candies[i] / mid);
        }
        return (cnt >= k);
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int low = 1;
        int high = *max_element(candies.begin() , candies.end());

        int ans = 0;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(isPossible(mid , candies , k)){
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};