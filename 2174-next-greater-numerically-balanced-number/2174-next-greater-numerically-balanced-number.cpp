class Solution {
public:

    bool isPossible(int x) {
        vector<int> freq(10 , 0);

        while(x > 0) {
            int dig = x % 10;
            freq[dig]++;
            x /= 10;
        }
        
        for(int i=0; i<10; i++) {
            if(freq[i] > 0) {
                if(freq[i] != i) return false;
            } 
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int ans = 0;

        for(int i=1; i<=1e7; i++) {
            if(i > n && isPossible(i)) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};