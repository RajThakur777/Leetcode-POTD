class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) { 
        int m = players.size();
        int n = trainers.size();

        sort(players.begin() , players.end());
        sort(trainers.begin() , trainers.end());

        int i = 0;
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if((i < m) && trainers[j] >= players[i]) {
                cnt++;
                i++;
            } 
        }
        return cnt;
    }
};