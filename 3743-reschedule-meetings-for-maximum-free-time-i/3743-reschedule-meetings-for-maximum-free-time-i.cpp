class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> gaps(n+1);
        gaps[0] = startTime[0];
        gaps[n] = eventTime - endTime[n-1];

        for(int i=1; i<n; i++) {
            gaps[i] = startTime[i] - endTime[i-1];
        }

        int ans = INT_MIN;
        int sum = 0;

        int i = 0;
        for(int j=0; j<=n; j++) {
            sum += gaps[j];

            while((j - i + 1) > (k + 1)) {
                sum -= gaps[i];
                i++;
            }

            if((j - i + 1) == k + 1) {
                ans = max(ans , sum);
            }
        }
        return ans;
    }
};