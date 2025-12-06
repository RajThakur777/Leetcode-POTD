class Solution {
public:
    bool isPrime(int num) {
        if(num < 2) return false;

        for(int i=2; i*i<=num; i++) {
            if(num % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    bool completePrime(int num) {  
        string str = to_string(num);

        int num1 = 0;
        for(int i=0; i<str.size(); i++) {
            int n = str[i] - '0';

            num1 = (num1 * 10) + n;

            if(!isPrime(num1)) {
                return false;
            }
        }

        int num2 = 0;
        for(int i=str.size()-1; i>=0; i--) {
            int n = str[i] - '0';

            num2 = (num2 * 10) + n;

            string str2 = to_string(num2);

            reverse(str2.begin() , str2.end());

            int num3 = stoi(str2);

            if(!isPrime(num3)) {
                return false;
            }
        }
        return true;
    }
};