// class Solution {
// public:
//     int countGoodSubstrings(string s) {
//         int n = s.size(); 

//         int cnt = 0;

//         if(s.size() < 3) return 0;  

//         for(int i=0; i<=n-3; i++){
//             if(s[i] != s[i+1] && s[i+1] != s[i+2] && s[i+2] != s[i]){
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };






//Using Sliding Window:
class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();

        int mp[26] = {0};

        if(s.size() < 3) return 0;

        int cnt = 0;
        int dup = 0;

        for(int i=0; i<n; i++){
            mp[s[i] - 'a']++;

            if(mp[s[i] - 'a'] == 2){
                dup++;
            }

            if(i < 2) continue;

            if(dup == 0) cnt++;

            mp[s[i-2] - 'a']--;

            if(mp[s[i-2] - 'a'] == 1){
                dup--;
            }
        }
        return cnt;
    }
};