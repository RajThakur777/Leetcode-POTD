class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>> &intervals){
        int n = intervals.size();

        vector<vector<int>> res;

        sort(intervals.begin() , intervals.end());

        res.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            if(intervals[i][0] < res.back()[1]){
                res.back()[1] = max(res.back()[1] , intervals[i][1]);
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> horizontal;
        vector<vector<int>> vertical;

        for(auto &it : rectangles){
            int x1 = it[0];
            int y1 = it[1];
            int x2 = it[2];
            int y2 = it[3];

            horizontal.push_back({x1 , x2});
            vertical.push_back({y1 , y2});
        } 

        sort(horizontal.begin() , horizontal.end());
        sort(vertical.begin() , vertical.end());

        vector<vector<int>> x = merge(horizontal);
        vector<vector<int>> y = merge(vertical);

        if(x.size() >= 3 || y.size() >= 3) return true;

        return false;
    }
};