class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int , char>> pq;

        pq.push({a , 'a'});
        pq.push({b , 'b'});
        pq.push({c , 'c'});

        int n = pq.top().first;

        string ans(n , ' ');

        int freq = pq.top().first;
        char ch = pq.top().second;

        pq.pop();

        int i = 0;
        while(i < n && freq > 0){
            ans[i] += ch;
            ans[i+1] += ch;

            freq -= 2;

            i += 3;

            if(i >= n){
                i = 1;
                break;
            }
        }

        char ch2 = pq.top().second;
        int freq2 = pq.top().first;

        pq.pop();

        while(i < n && freq2 > 0){
            ans[i] += ch2;
            i += 2;
            freq2--;
        }

        char ch3 = pq.top().second;
        int freq3 = pq.top().first;

        pq.pop();

        while(i < n && freq3 > 0){
            ans[i] += ch3;
            i += 2;
            freq3--;
        }

        int idx = -1;
        for(int i=0; i<n; i++){
            if(ans[i] == ' '){
                idx = i;
                break;
            }
        }
        return ans.substr(0 , idx+1);
    }
};