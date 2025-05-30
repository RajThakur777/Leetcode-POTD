// class myComparator {
//     public:
//     bool operator() (const pair<int , string> &p1, const pair<int , string> &p2) {
//       if(p1.first == p2.first) return p1.second < p2.second;
      
//       return p1.first > p2.first;
//     }
// };

// class Solution {
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         int n = words.size();

//         vector<string> ans(k);

//         unordered_map<string , int> map;
//         for(int i=0; i<n; i++){
//             map[words[i]]++;
//         }

//         priority_queue<pair<int , string> , vector<pair<int , string>> , myComparator> pq;

//         for(auto it : map){
//             pq.push({it.second , it.first});

//             if(pq.size() > k){
//                pq.pop();
//             }
//         }

//         int m = k-1;
//         while(pq.size() > 0){
//             ans[m--] = pq.top().second;
//             pq.pop();
//         }
//         return ans;
//     }
// };






class myComparator {
    public:
    bool operator() (const pair<int , string> &p1, const pair<int , string> &p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      
      return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();

        vector<string> ans(k);

        unordered_map<string , int> map;
        for(int i=0; i<n; i++){
            map[words[i]]++;
        }

        priority_queue<pair<int , string> , vector<pair<int , string>> , myComparator> pq;

        for(auto it : map){
            pq.push({it.second , it.first});

            if(pq.size() > k){
               pq.pop();
            }
        }

        int m = k-1;
        while(pq.size() > 0){
            ans[m--] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};