class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();

        map<char , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[word[i]]++;
        }

        int ans = INT_MAX;
        for(auto [ch , f1] : mpp) {
            int cnt = 0;
            for(auto [ch , f2] : mpp) {
                int diff = f2 - f1;
                if(f2 < f1) {
                    cnt += f2;
                }
                else if(diff > k) {
                    cnt += (f2 - f1 - k);
                }
            }
            ans = min(ans , cnt);
        }
        return ans;
    }
};