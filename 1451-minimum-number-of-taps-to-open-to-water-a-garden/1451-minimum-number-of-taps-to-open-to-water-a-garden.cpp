// //Recursion:
// class Solution {
// public:
//     int N;

//     int solve(int idx , vector<vector<int>> &tap_ranges , int maxEnd) {
//         if(idx >= tap_ranges.size()) {
//             return (maxEnd >= N) ? 0 : 1e9;
//         }

//         if(tap_ranges[idx][0] > maxEnd) return 1e9;

//         int open_tap = 1 + solve(idx+1 , tap_ranges , max(maxEnd , tap_ranges[idx][1]));

//         int not_open_tap = solve(idx+1 , tap_ranges , maxEnd);

//         return min(open_tap , not_open_tap);
//     }

//     int minTaps(int n, vector<int>& ranges) { 
//         N = n;

//         vector<vector<int>> tap_ranges;

//         for(int i=0; i<=n; i++) {
//             int value = ranges[i];

//             int left = max(0 , i-value);
//             int right = min(i+value , n);

//             tap_ranges.push_back({left , right});
//         } 

//         sort(tap_ranges.begin() , tap_ranges.end());

//         int ans = solve(0 , tap_ranges , 0);

//         return (ans == 1e9) ? -1 : ans;
//     }
// };




//Recursion+Memoization:
class Solution {
public:
    int N;
    map<pair<int , int> , int> mpp;

    int solve(int idx , vector<vector<int>> &tap_ranges , int maxEnd) {
        if(idx >= tap_ranges.size()) {
            return (maxEnd >= N) ? 0 : 1e9;
        }

        if(tap_ranges[idx][0] > maxEnd) return 1e9;

        if(mpp.find({idx , maxEnd}) != mpp.end()) {
            return mpp[{idx , maxEnd}];
        }

        int open_tap = 1 + solve(idx+1 , tap_ranges , max(maxEnd , tap_ranges[idx][1]));

        int not_open_tap = solve(idx+1 , tap_ranges , maxEnd);

        return mpp[{idx , maxEnd}] = min(open_tap , not_open_tap);
    }

    int minTaps(int n, vector<int>& ranges) { 
        N = n;

        vector<vector<int>> tap_ranges;

        for(int i=0; i<=n; i++) {
            int value = ranges[i];

            int left = max(0 , i-value);
            int right = min(i+value , n);

            tap_ranges.push_back({left , right});
        } 

        sort(tap_ranges.begin() , tap_ranges.end());

        int ans = solve(0 , tap_ranges , 0);

        return (ans == 1e9) ? -1 : ans;
    }
};