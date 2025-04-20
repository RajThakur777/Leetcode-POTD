class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();

        map<int , int> mpp;

        for(int i=0; i<n; i++){
            mpp[answers[i]]++;
        }

        int ans = 0;
        for(auto it : mpp){
            int x = it.first;
            int val = it.second;

            int groupsSize = ceil((double)val / (x + 1));
            ans += (groupsSize) * (x + 1);
        }
        return ans;
    }
};