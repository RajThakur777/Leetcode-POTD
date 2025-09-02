class Solution {
public:

    bool isValid(vector<vector<int>>& points , int x1 , int y1 , int x2 , int y2) {
        for(int i=0; i<points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            if(x == x1 && y == y1) continue;
            if(x == x2 && y == y2) continue;

            if((x >= x1 && x <= x2) && (y >= y2 && y <= y1)) {
                return false;
            }
        }
        return true;
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        int cnt = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                
                int p1_x = points[i][0];
                int p1_y = points[i][1];

                int p2_x = points[j][0];
                int p2_y = points[j][1];

                if(p1_y >= p2_y && p1_x <= p2_x && isValid(points , p1_x , p1_y , p2_x , p2_y)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};