class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int , int> mpp;

        string res = to_string(n);

        for(int i=0; i<res.size(); i++) {
            mpp[res[i]-'0']++;
        }

        int mini = INT_MAX;
        for(auto it : mpp) {
            mini = min(mini , it.second);
        }

        int ans = 0;
        for(auto it : mpp) {
            if(it.second == mini) {
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};