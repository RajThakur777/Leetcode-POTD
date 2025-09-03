//Sorting Approach:
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        auto lamda = [](vector<int> &point1 , vector<int> &point2) {
            if(point1[0] == point2[0]) {
                return point1[1] > point2[1];
            }
            return point1[0] < point2[0];
        };

        sort(points.begin() , points.end() , lamda);

        int ans = 0;

        for(int i=0; i<n; i++) {
            int maxi = INT_MIN;
            int x1 = points[i][0];
            int y1 = points[i][1];

            for(int j=i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y2 > y1) continue;

                if(maxi < y2) {
                    ans++;
                    maxi = y2;
                }
            }
        }
        return ans;
    }
};