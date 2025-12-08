class Solution {
public:
    #define ll long long 
    
    int largestPrime(int n) {   
        vector<bool> isPrime(n+1 , true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(ll i=2; i<=n; i++) {
            if(isPrime[i]) {
                for(ll j=i*i; j<=n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> Primes;
        for(int i=2; i<=n; i++) {
            if(isPrime[i]) {
                Primes.push_back(i);
            }
        }

        long long sum = 0;
        long long ans = 0;

        for(int i=0; i<Primes.size(); i++) {
            sum += Primes[i];

            if(sum > n) {
                break;
            }

            if(isPrime[sum]) {
                ans = max(ans , sum);
            }
        }
        return (int)ans;
    }
};