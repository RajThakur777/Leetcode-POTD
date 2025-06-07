struct CustomCompare {
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) const {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
};

class Solution {
public:
    string clearStars(string& s) {
        int n = s.size();
        priority_queue<pair<char,int>, vector<pair<char,int>>, CustomCompare> pq;

        for(int i=0;i<n;++i){
            if(s[i] == '*'){
                pair<char, int> temp = pq.top();
                pq.pop();
                s[temp.second] = '*';
                s[i] = '*';
            }
            else{
                pq.emplace(s[i], i);
            }
        }

        string res = "";
        for(const auto& c:s){
            if(c != '*') res.append(1, c);
        }

        return res;
    }
};