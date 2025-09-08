class Solution {
public:

    bool valid(int x) {
        while(x > 0) {
            int dig = x % 10;

            if(dig == 0) return false;

            x /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;

        for(int i=1; i<=n; i++) {
            int a = i;
            int b = n-i;

            if(valid(a) && valid(b)) {
                ans.push_back(a);
                ans.push_back(b);
                break;
            }
        }
        return ans;
    }
};