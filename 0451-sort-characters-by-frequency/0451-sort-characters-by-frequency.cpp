class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        map<char , int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }

        priority_queue<pair<int , char>> pq;
        for(auto it : mpp){
            pq.push({it.second , it.first});
        }

        string ans = "";

        while(!pq.empty()){
            char ch = pq.top().second;
            int freq = pq.top().first;

            pq.pop();

            ans.append(freq , ch);
        }
        return ans;
    }
};