class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        map<int, bool> m;
        for(int i = 0; i<fronts.size(); i++){
            m[fronts[i]] = true;
            m[backs[i]] = true;
        }

        for(int i = 0; i<fronts.size(); i++){
            if(fronts[i] == backs[i]) m[fronts[i]] = false;
        }
        int ans = 0;
        for(auto it: m){
            if(it.second){
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};