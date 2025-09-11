class Solution {
public:

    bool isVowel(char ch) {
        return ((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'));
    }

    string sortVowels(string s) { 
        int n = s.size();

        string ans;
        string res;

        for(int i=0; i<n; i++) {
            if(isVowel(s[i])) {
                res += s[i];
            }
        }

        sort(res.begin() , res.end());

        int k = 0;

        for(int i=0; i<n; i++) {
            if(!isVowel(s[i])) {
                ans += s[i];
            }
            else {
                ans += res[k];
                k++;
            }
        }
        return ans;
    }
};