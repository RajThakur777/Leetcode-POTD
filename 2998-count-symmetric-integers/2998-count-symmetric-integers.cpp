class Solution {
public:

    int totalDigits(int n){
        int sum = 0;

        while(n > 0){
            sum += (n % 10);
            n = n / 10;
        }
        return sum;
    }

    int cntofDigits(int n){
        int cnt = 0;

        while(n > 0){
            n = n / 10;
            cnt++;
        }
        return cnt;
    }

    bool isSymmetric(int n){
        if(cntofDigits(n) % 2 != 0) return false;

        int val = cntofDigits(n) / 2;

        int total = totalDigits(n);

        int first = 0;
        int last = 0;
        int cnt = 0;
        
        for(int i=0; i<val; i++){
            last += (n % 10);
            n = n / 10;
        }

        first = total - last;

        return first == last;
    } 

    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;

        for(int i=low; i<=high; i++){
            if(isSymmetric(i)){
                cnt++;
            }
        }
        return cnt;
    }
};