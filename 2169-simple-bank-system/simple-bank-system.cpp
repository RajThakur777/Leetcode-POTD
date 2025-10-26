class Bank {
public:
    vector<long long> res;
    Bank(vector<long long>& balance) {
        res = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        int Ac1 = account1 - 1;
        int Ac2 = account2 - 1;

        if(Ac1 > res.size() - 1 || Ac2 > res.size() - 1) return false;

        if(res[Ac1] < money) return false;

        res[Ac1] -= money;
        res[Ac2] += money;

        return true;
    }
    
    bool deposit(int account, long long money) {
        int Ac = account - 1;

        if(Ac > res.size() - 1) return false;

        res[Ac] += money;

        return true;
    }
    
    bool withdraw(int account, long long money) {
        int Ac = account - 1;

        if(Ac > res.size() - 1) return false;

        if(res[Ac] < money) return false;

        res[Ac] -= money;

        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */