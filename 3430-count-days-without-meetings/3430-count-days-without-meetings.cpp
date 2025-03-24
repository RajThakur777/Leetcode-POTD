class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            if (interval[0] <= prev[1]) {
                prev[1] = max(prev[1], interval[1]);
            } else {
                merged.push_back(prev);
                prev = interval;
            }
        }

        merged.push_back(prev);
        return merged;        
    }

    int countDays(int days, vector<vector<int>>& meetings) { 
        vector<vector<int>> ans = merge(meetings);

        sort(ans.begin() , ans.end());

        int res = (ans[0][0] - 1) + (days - ans[ans.size() - 1][1]);

        if(ans.size() == 1) {
            return ((days - ans[0][1]) + (ans[0][0] - 1));
        }

        for(int i=0; i<ans.size()-1; i++){
            res += abs(ans[i+1][0] - ans[i][1] - 1);
        }
        return res;
    }
};