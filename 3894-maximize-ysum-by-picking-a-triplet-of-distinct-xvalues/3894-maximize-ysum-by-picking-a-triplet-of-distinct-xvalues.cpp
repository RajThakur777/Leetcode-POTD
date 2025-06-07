class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();

        set<int> st;
        for(int i = 0; i < n; i++) {
            st.insert(x[i]);
        }

        if(st.size() < 3) return -1;

        vector<pair<int, int>> p;
         for(int i = 0; i < n; i++) {
             p.push_back({x[i], y[i]});
        }

        sort(p.begin(), p.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second > b.second;
        });

        int ans = p[0].second;
        int cnt = 0;
        set<int> st2;
        st2.insert(p[0].first);
        for(int i=1; i<n; i++){
            if(st2.find(p[i].first) == st2.end()){
                cnt++;
                ans += p[i].second;
                st2.insert(p[i].first);
            }
            else {
                continue;
            }
            if(cnt == 2) break;
        }
        return ans;
    }
};