class Solution {
public:

    bool isPrime(long long n){
        if(n < 2) return false;

        for(long long i=2; i*i<=n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    
    long long sumOfLargestPrimes(string s) {
        vector<long long> res;
        set<long long> st;

        for(long long i=0; i<s.size(); i++){
            for(long long j=i; j<s.size(); j++){
                string str = s.substr(i , (j - i + 1));

                if(isPrime(stoll(str)) && st.find(stoll(str)) == st.end()){
                    res.push_back(stoll(str));
                    st.insert(stoll(str));
                }
            }
        }

        vector<long long> ans;
        for(auto it : st){
            ans.push_back(it);
        }
        
        if(st.size() < 3){
            long long sum = 0;
            for(int i=0; i<res.size(); i++){
                 sum += res[i];
            }
             return sum;
        }

        sort(ans.rbegin() , ans.rend());

        return ans[0] + ans[1] + ans[2];
    }
};