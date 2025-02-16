class Solution {
public:
    long long maxWeight(vector<int>& pizzas) { 
        int n = pizzas.size();

        long long ans = 0;

        int days = (n / 4);

        int even = 0;
        for(int i=1; i<=days; i++){
            if(i % 2 == 0){
                even++;
            }
        }
        int odd = days - even;

        sort(pizzas.begin() , pizzas.end());

        vector<int> visited(n+1 , 0);

        int val = 0;
        for(int i=n-1; i>=0 && val != odd; i--){
            ans += pizzas[i];
            visited[i] = 1;
            val++;
        }

        int cnt = 0;
        for(int i=n-odd-2; i>0 && cnt != even; i-=2){
            ans += pizzas[i];
            cnt++;
        }
        return ans;
    }
};