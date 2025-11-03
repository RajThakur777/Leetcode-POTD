class Solution {
public:

    bool isPossible(int mid , vector<int> &weights , int days) {
        int sum = 0;
        int cnt = 1;

        for(int i=0; i<weights.size(); i++) {
            if(sum + weights[i] > mid) {
                sum = weights[i];
                cnt++;
            }
            else {
                sum += weights[i];
            }
        }
        return cnt <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int ans = 0;

        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += weights[i];
        }

        int low = *max_element(weights.begin() , weights.end());
        int high = sum;

        while(low <= high) {
            int mid = low + ((high - low) / 2);

            if(isPossible(mid , weights , days)) {
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