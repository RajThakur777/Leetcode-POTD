class Solution {
public:
    const int MOD = 1337;
    int myPowe(int a , int k){
        a %= MOD;

        int res = 1;
        for(int i=0; i<k; i++){
            res = (res * a) % MOD;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;

        int lastDigit = b.back();
        b.pop_back();

        int ans1 = myPowe(superPow(a , b) , 10);
        int ans2 = myPowe(a , lastDigit);

        return (ans1 * ans2) % MOD;
    }
};