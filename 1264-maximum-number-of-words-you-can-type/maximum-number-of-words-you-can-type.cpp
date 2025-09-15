class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> st;
        for (char ch : brokenLetters) {
            st.insert(ch);
        }

        int cnt = 0;
        int i = 0;

        while (i < text.size()) {
            bool flag = true;

            while (i < text.size() && text[i] != ' ') {
                if (st.find(text[i]) != st.end()) {
                    flag = false;
                }
                i++;
            }

            if (flag) {
                cnt++;
            }
            i++;
        }

        return cnt;
    }
};
