// class Solution {
// public:
//     int findTheWinner(int n, int k) { 
//         queue<int> q;

//         for(int i=1; i<=n; i++){
//             q.push(i);
//         } 

//         while(q.size() > 1){
//             for(int i=0; i<k-1; i++){
//                 q.push(q.front());
//                 q.pop();
//             }
//             q.pop();
//         }
//         return q.front();
//     }
// };



//Using arrays:
class Solution {
public:
    int findTheWinner(int n, int k) { 
        vector<int> v;
        for(int i=0; i<n; i++){
            v.push_back(i+1);
        }

        int i = 0;

        while(v.size() > 1){
            int idx = (i + k - 1) % v.size();

            v.erase(v.begin() + idx);

            i = idx;
        }
        return v.front();
    }
};