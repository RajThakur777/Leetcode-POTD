class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();

        map<int , vector<int>> mpp1;
        map<int , vector<int>> mpp2;

        for(int i=0; i<m; i++){
            mpp1[buildings[i][0]].push_back(buildings[i][1]);
            mpp2[buildings[i][1]].push_back(buildings[i][0]);
        }

        for (auto& [_, v] : mpp1) {
            sort(v.begin(), v.end());
        }
        for (auto& [_, v] : mpp2) {
            sort(v.begin(), v.end());
        }

        int cnt = 0;

        for(int i=0; i<m; i++){
            int val1 = buildings[i][0];
            int val2 = buildings[i][1];

            auto& r = mpp1[val1];
            auto& c = mpp2[val2];

            auto it1 = upper_bound(r.begin() , r.end() , val2);
            auto it2 = lower_bound(r.begin() , r.end() , val2);
            auto it3 = upper_bound(c.begin() , c.end() , val1);
            auto it4 = lower_bound(c.begin() , c.end() , val1);

            if(it1 != r.end() && it2 != r.begin() && it3 != c.end() && it4 != c.begin()){
                cnt++;
            }
        }
        return cnt;
    }
};