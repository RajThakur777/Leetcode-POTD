class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();

        vector<int> diff;

        for(int i=0; i<n; i++){
            diff.push_back(capacity[i] - rocks[i]);
        }

        sort(diff.begin() , diff.end());

        int cnt = 0;
        for(int i=0; i<diff.size(); i++){
            if(diff[i] == 0) cnt++;
        }

        for(int i=0; i<diff.size(); i++){
            if(diff[i] <= additionalRocks && diff[i] > 0){
                cnt++;
                additionalRocks -= diff[i];
            }
        }
        return cnt;
    }
};