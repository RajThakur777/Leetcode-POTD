class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin() , intervals.end());

        vector<vector<int>> ans;

        vector<int> prev = {intervals[0][0] , intervals[0][1]};

        for(int i=1; i<n; i++) {
            if(intervals[i][0] <= prev[1]) {
                prev[0] = min(prev[0] , intervals[i][0]);
                prev[1] = max(prev[1] , intervals[i][1]);
            }
            else {
                ans.push_back(prev);
                prev = {intervals[i][0] , intervals[i][1]};
            }
        }
        ans.push_back(prev);
        return ans;
    }
};