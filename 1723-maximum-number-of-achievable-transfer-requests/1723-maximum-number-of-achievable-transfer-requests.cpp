//Recursion + Backtracking :
class Solution {
public:
    int N;

    void solve(int idx , vector<vector<int>>& requests , int &res , vector<int> &resultant , int cnt) {
        if(idx >= N) {
            bool flag = true;
            for(auto x : resultant) {
                if(x != 0) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                res = max(res , cnt);
            }
            return;
        }

        int from = requests[idx][0];
        int to = requests[idx][1];
        //take
        resultant[from]--;
        resultant[to]++;
        solve(idx+1 , requests , res , resultant , cnt+1);
        resultant[from]++;
        resultant[to]--;

        //not_take
        solve(idx+1 , requests , res , resultant , cnt);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        N = requests.size();

        int res = INT_MIN;

        vector<int> resultant(n , 0);

        solve(0 , requests , res , resultant , 0);

        return res;
    }
};