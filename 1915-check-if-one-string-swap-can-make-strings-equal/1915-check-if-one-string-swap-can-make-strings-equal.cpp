class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;

        int freq1[26] = {0};
        int freq2[26] = {0};

        int cnt = 0;

        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                cnt++;

                if(cnt > 2) return false;
            }
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
};