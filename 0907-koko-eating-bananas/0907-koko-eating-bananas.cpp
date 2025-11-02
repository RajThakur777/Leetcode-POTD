class Solution {
public:

    bool isPossible(int mid , vector<int> &piles , int h) {
        long long cnt = 0;

        for(int i=0; i<piles.size(); i++) {
            cnt += ((piles[i] + mid - 1) / mid);
        }
        return (cnt <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin() , piles.end());

        int ans = 0;

        while(low <= high) {
            int mid = low + ((high - low) / 2);

            if(isPossible(mid , piles , h)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};