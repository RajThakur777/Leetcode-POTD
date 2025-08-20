class Solution {
public:
    int sz;

    bool solve(int idx , int n , vector<int> &res , vector<bool> &used) {
        if(idx >= sz) return true;

        if(res[idx] != -1) {
            return solve(idx+1 , n , res , used);
        }

        for(int num=n; num>=1; num--) {
            if(used[num]) continue;

            res[idx] = num;
            used[num] = true;

            if(num == 1) {
                if(solve(idx+1 , n , res , used) == true) {
                    return true;
                } 
            }
            else {
                int j = num + idx;
                if(j < res.size() && res[j] == -1) {
                    res[j] = num;

                    if(solve(idx+1 , n , res , used) == true) {
                        return true;
                    }
                    res[j] = -1;
                }
            }

            res[idx] = -1;
            used[num] = false;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        sz = 2 * n - 1;

        vector<int> res(sz , -1);

        vector<bool> used(n+1 , false);

        solve(0 , n , res , used);

        return res;
    }
};