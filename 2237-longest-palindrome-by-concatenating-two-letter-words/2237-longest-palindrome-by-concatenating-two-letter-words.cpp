class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();

        int ans = 0;
        unordered_map<string , int> mpp;
        for(int i=0; i<n; i++){
            string str = words[i];

            string rev;
            rev += str[1];
            rev += str[0];

            if(mpp.find(rev) != mpp.end() && mpp[rev] > 0){
                ans += 4;
                mpp[rev]--;
            }
            else {
                mpp[str]++;
            }
        }

        for(auto it : mpp){
            int cnt = it.second;
            string str = it.first;

            if(cnt > 0 && str[0] == str[1]){
                ans += 2;
                break;
            }
        }
        return ans;
    }
};