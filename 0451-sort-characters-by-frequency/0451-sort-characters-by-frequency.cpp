class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char , int> mpp;

        for(int i=0; i<n; i++) {
            mpp[s[i]]++;
        }

        priority_queue<pair<int , char>> pq;
        for(auto it : mpp) {
            pq.push({it.second , it.first});
        }

        string ans;

        while(!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;

            pq.pop();

            ans += string(freq , ch);
        }
        return ans;
    }
};