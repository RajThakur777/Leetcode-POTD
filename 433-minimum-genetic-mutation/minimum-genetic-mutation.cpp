class Solution {
public:

    void fillNeighbours(queue<string> &q , string &str , unordered_set<string> &st) {
        for(int i=0; i<8; i++) {
            char ch = str[i];

            str[i] = 'A';
            if(st.find(str) != st.end()) {
                q.push(str);
            } 

            str[i] = 'C';
            if(st.find(str) != st.end()) {
                q.push(str);
            } 

            str[i] = 'G';
            if(st.find(str) != st.end()) {
                q.push(str);
            } 

            str[i] = 'T';
            if(st.find(str) != st.end()) {
                q.push(str);
            } 

            str[i] = ch;
        }
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin() , bank.end());

        queue<string> q;
        q.push(startGene);

        int level = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                string str = q.front();
                q.pop();

                if(str == endGene) return level;

                st.erase(str);

                fillNeighbours(q , str , st);                
            }
            level++;
        }
        return -1;
    }
};