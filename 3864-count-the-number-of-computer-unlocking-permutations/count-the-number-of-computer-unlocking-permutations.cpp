class Solution {
public:

    const int mod = 1e9 + 7;

    long long factorial(int num) {
        if(num == 0 || num == 1) return 1;

        return (num % mod * factorial(num - 1) % mod);
    }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        unordered_map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[complexity[i]]++;
        }

        int mini = *min_element(complexity.begin() , complexity.end());

        if(complexity[0] != mini || mpp[mini] >= 2) {
            return 0;
        }

        return (int)factorial(n - 1) % mod;
    }
};