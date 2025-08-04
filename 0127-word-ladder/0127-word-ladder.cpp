//BFS:
class Solution {
public:

    void fillNeighbour(queue<string> &q , string &curr , unordered_set<string> &st) {
        for(int i=0; i<curr.size(); i++) {
            char ch = curr[i];

            for(int j=0; j<26; j++) {
                char c = j + 'a';

                curr[i] = c;

                if(st.find(curr) != st.end()) {
                    q.push(curr);
                }
            } 
            curr[i] = ch;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(begin(wordList) , end(wordList));

        queue<string> q;
        q.push(beginWord);

        int level = 0;

        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                string curr = q.front();
                q.pop();

                if(curr == endWord) return level + 1;

                st.erase(curr);

                fillNeighbour(q , curr , st);
            }
            level++;
        } 
        return 0;
    }
};