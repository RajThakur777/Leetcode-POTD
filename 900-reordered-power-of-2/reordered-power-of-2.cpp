class Solution {
public:

    bool solve(unordered_map<int , int> &mpp , vector<int> &digits , vector<int> temp) {
        if(temp.size() == digits.size()) {
            int num = 0;
            if(temp[0] == 0) return false;
            for(int i=0; i<temp.size(); i++) {
                num = (num * 10) + temp[i];
            }
            return __builtin_popcount(num) == 1;
        }

        for(auto it : mpp) {
            if(it.second == 0) continue;

            temp.push_back(it.first);
            mpp[it.first]--;

            if(solve(mpp , digits , temp)) {
                return true;
            }

            temp.pop_back();
            mpp[it.first]++;
        }
        return false;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> digits;

        vector<int> temp;

        while(n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        unordered_map<int , int> mpp;
        for(int i=0; i<digits.size(); i++) {
            mpp[digits[i]]++;
        }

        return solve(mpp , digits , temp);
    }
};