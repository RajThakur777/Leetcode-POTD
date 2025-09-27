class Solution {
public:
    string majorityFrequencyGroup(string s) {
        int n = s.size();

        map<char , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[s[i]]++;
        }

        priority_queue<pair<int , int>> pq;
        
        for(auto it : mpp) {
            int val = it.second;
            int cnt = 0;

            for(auto it2 : mpp) {
                if(it2.second == val) {
                    cnt++;
                }
            }
            pq.push({val , cnt});
        }

        priority_queue<pair<int , int>> pq2;
        while(!pq.empty()) {
            int v1 = pq.top().first;
            int v2 = pq.top().second;

            pq2.push({v2 , v1});
            pq.pop();
        }

        string ans;
        int freq = pq2.top().second;

        for(auto it : mpp) {
            if(it.second == freq) {
                ans += it.first;
            }
        }
        return ans;
    }
};