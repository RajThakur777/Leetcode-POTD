class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i <= j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool binary(int number) {
        string str;

        int bits = log2(number);
        
        for(int j=0; j<=bits; j++) {
            if(((number) & (1 << j)) > 0) {
                str += '1';
            }
            else {
                str += '0';
            }
        }
        return isPalindrome(str);
    }
    
    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int num = nums[i];

            if(binary(num)) {
                ans[i] = 0;
            }
            else {
                int ops1 = 0;
                int ops2 = 0;
                int copy1 = num;
                int copy2 = num;

                while(!(binary(copy1))) {
                    ops1++;
                    copy1++;
                }

                while(!(binary(copy2))) {
                    ops2++;
                    copy2--;
                }

                ans[i] = min(ops1 , ops2);
            }
        }
        return ans;
    }
};