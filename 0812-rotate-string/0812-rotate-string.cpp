class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        int n = goal.size();

        if(m != n) return false;

        for(int i=0; i<m; i++) {
            string str1 = s.substr(i+1 , n-i+2);

            string str2 = s.substr(0 , i+1);

            str1 += str2;

            if(str1 == goal) return true;
        }
        return false;
    }
};