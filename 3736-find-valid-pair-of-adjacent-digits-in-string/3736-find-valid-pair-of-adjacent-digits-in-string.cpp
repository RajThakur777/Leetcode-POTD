class Solution {
    public: string findValidPair(string s) {
        int n = s.size();

        map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i] - '0']++;
        }

        string ans;
        for(int i=0; i<n-1; i++){
            if((s[i] - '0') != (s[i+1] - '0') && (mpp[s[i] - '0'] == (s[i] - '0')) && (mpp[s[i+1] - '0'] == (s[i+1] - '0'))){
                ans += s[i];
                ans += s[i+1];
                break;
            }
        }
        return ans;
    }
};