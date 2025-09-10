class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> sadUsers;

        for(int i=0; i<friendships.size(); i++) {
            int u = friendships[i][0];
            int v = friendships[i][1];

            vector<int> v1 = languages[u-1];
            vector<int> v2 = languages[v-1];

            bool flag = false;

            set<int> s1;
            for(int j=0; j<v1.size(); j++) {
                s1.insert(v1[j]);
            }

            for(int k=0; k<v2.size(); k++) {
                if(s1.find(v2[k]) != s1.end()) {
                    flag = true;
                    break;
                }
            }

            if(!flag) {
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        int ans = INT_MAX;

        for(int i=1; i<=n; i++) {
            int lang = i;

            int cnt = 0;

            for(auto it : sadUsers) {
                int user = it;
                vector<int> l = languages[user-1];
                bool flag = false;

                for(int k=0; k<l.size(); k++) {
                    if(l[k] == lang) {
                        flag = true;
                        break;
                    }
                }

                if(flag) {
                    cnt++;
                }
            }
            ans = min(ans , (int)sadUsers.size() - cnt);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};