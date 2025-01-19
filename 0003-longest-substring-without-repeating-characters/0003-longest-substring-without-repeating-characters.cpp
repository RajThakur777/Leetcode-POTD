class Solution {
public:
    int lengthOfLongestSubstring(string s) { 
        int n = s.size();

        int maxi = 0;
        int i = 0;

        map<char , int> mpp;
        for(int j=0; j<n; j++){
            mpp[s[j]]++;

            while(mpp[s[j]] > 1){
                mpp[s[i]]--;
                i++;
            }

            maxi = max(maxi , j - i + 1);
        }
        return maxi;
    }
};