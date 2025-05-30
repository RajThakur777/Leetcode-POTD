// class Solution {
// public:

//     bool isPrime(int n){
//         if(n <= 1) return false;

//         for(int i=2; i*i<=n; i++){
//             if(n % i == 0) return false;
//         }
//         return true;
//     }

//     vector<int> closestPrimes(int left, int right) { 
//         vector<int> ans;

//         vector<int> prime;

//         for(int i=left; i<=right; i++){
//             if(isPrime(i)){
//                 prime.push_back(i);
//             }
//         } 

//         if(prime.size() <= 1) return {-1 , -1};

//         sort(prime.begin() , prime.end());

//         int mini = INT_MAX;
//         int val1 = 0;
//         int val2 = 0;

//         for(int i=0; i<prime.size()-1; i++){
//             mini = min(mini , prime[i+1] - prime[i]);
//         }

//         for(int i=0; i<prime.size()-1; i++){
//             int diff = prime[i+1] - prime[i];

//             if(diff == mini){
//                 val1 = prime[i];
//                 val2 = prime[i+1];
//                 break;
//             }
//         }  
//         return {val1 , val2};
//     }
// };






//Using seive:
class Solution {
public:

    vector<bool> seive(int right){
        vector<bool> Primes(right+1 , true);

        Primes[0] = false;
        Primes[1] = false;

        for(int i=2; i*i<=right; i++){
            if(Primes[i] == true){
                for(int j=i*i; j<=right; j+=i){
                    Primes[j] = false;
                }
            }
        }
        return Primes;
    }

    vector<int> closestPrimes(int left, int right) { 

        vector<bool> isPrime = seive(right);

        vector<int> primes;

        for(int i=left; i<=right; i++){
            if(isPrime[i] == true){
                primes.push_back(i);
            }
        } 

        int minDiff = INT_MAX;

        vector<int> ans = {-1 , -1};

        for(int i=1; i<primes.size(); i++){
            int diff = primes[i] - primes[i-1];

            if(diff < minDiff){
                minDiff = diff;
                ans = {primes[i-1] , primes[i]};
            }
        }
        return ans;
    }
};