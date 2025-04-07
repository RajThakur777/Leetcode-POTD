class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        unordered_map<char , int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }

        priority_queue<pair<int , char>> pq;
        for(auto it : mpp){
            pq.push({it.second , it.first});
        }

        if(pq.top().first > ((n + 1) / 2)) return "";

        string ans(n , ' ');

        int idx = 0;
        while(!pq.empty()){
            pair<int , char> p = pq.top();
            pq.pop();

            for(int i=0; i<p.first; i++){
                ans[idx] = p.second;
                idx += 2;

                if(idx >= n) {
                    idx = 1;
                }
            }
        }
        return ans;
    }
};