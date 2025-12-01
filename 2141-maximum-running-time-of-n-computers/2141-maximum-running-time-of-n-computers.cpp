class Solution {
public:

    bool isPossible(long long mid , int n , vector<int> &batteries) {
        long long sum = 0;

        long long cnt = 0;

        for(int i=0; i<batteries.size(); i++) {
            if(sum + batteries[i] < mid) {
                sum += batteries[i];
            }
            else {
                sum += batteries[i];
                long long v = sum - mid;
                cnt++;
                sum = v;
            }
        }
        return (cnt >= n);
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        int N = batteries.size();

        sort(batteries.begin() , batteries.end());

        long long sum = 0;

        for(int i=0; i<N; i++) {
            sum += batteries[i];
        }

        long long low = 1;
        long long high = (sum / n);

        long long ans = 0;

        while(low <= high) {
            long long mid = (low) + ((high - low) / 2);

            if(isPossible(mid , n , batteries)) {
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