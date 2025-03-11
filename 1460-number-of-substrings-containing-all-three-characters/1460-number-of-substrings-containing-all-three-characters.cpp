class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int ans = 0;

        int i = 0;
        map<char , int> mpp;

        for(int j=0; j<n; j++){
            mpp[s[j]]++;

            while(mpp.size() == 3){
                ans += (n - j);

                if(s[i] == 'a' || s[i] == 'b' || s[i] == 'c') {
                    mpp[s[i]]--;
                    
                    if(mpp[s[i]] == 0){
                        mpp.erase(s[i]);
                    }
                }
                i++;
            }
        }
        return ans;
    }
};