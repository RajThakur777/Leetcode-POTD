class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int , char>> pq;

        if(a > 0){
            pq.push({a , 'a'});
        }

        if(b > 0){
            pq.push({b , 'b'});
        }

        if(c > 0){
            pq.push({c , 'c'});
        }

        string ans;

        while(!pq.empty()){
            pair<int , char> p = pq.top();
            pq.pop();

            char ch = p.second;
            int freq = p.first;

            if(ans.size() >= 2 && ans[ans.size() - 1] == ch && ans[ans.size() - 2] == ch){
                if(pq.empty()) break;

                pair<int , char> p2 = pq.top();
                pq.pop();

                char ch2 = p2.second;
                int freq2 = p2.first;

                ans += ch2;
                freq2--;

                if(freq2 > 0){
                    pq.push({freq2 , ch2});
                }
                pq.push({freq , ch});
            }
            else {
                ans += ch;
                freq--;

                if(freq > 0){
                    pq.push({freq , ch});
                }
            }
        }
        return ans;
    }
};