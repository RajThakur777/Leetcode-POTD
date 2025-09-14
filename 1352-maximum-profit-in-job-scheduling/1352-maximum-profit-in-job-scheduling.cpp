class Solution {
public:
    int n;
    vector<int> dp;

    int binarysearch(int val , int i , vector<vector<int>> &vec) {
        int low = i;
        int high = n - 1;
        int ans = n; // return n if no job found

        while(low <= high) {
            int mid = (low + high) / 2;
            if(vec[mid][0] >= val) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int solve(int idx , vector<vector<int>> &vec) {
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int not_take = solve(idx+1 , vec);

        int next = binarysearch(vec[idx][1] , idx+1 , vec);
        int take = vec[idx][2] + solve(next , vec);

        return dp[idx] = max(take , not_take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>> vec(n , vector<int>(3));

        for(int i=0; i<n; i++) {
            vec[i][0] = startTime[i];
            vec[i][1] = endTime[i];
            vec[i][2] = profit[i];
        }

        // sort by start time
        sort(vec.begin(), vec.end());

        dp.assign(n, -1);

        return solve(0 , vec);
    }
};
