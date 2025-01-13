class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

        int len = 0;

        map<char , int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }

        for(auto it : mpp){
            if(it.second  % 2  == 0){
                len += 2;
            }
            else {
                len++;
            }
        }
        return len;
    }
};