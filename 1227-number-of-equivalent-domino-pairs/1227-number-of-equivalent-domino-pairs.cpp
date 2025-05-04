class Solution {
public:

    int rev(int num){
        int a = num % 10;
        num = num  / 10;
        int b = num;

        return a * 10 + b;
    }

    int numEquivDominoPairs(vector<vector<int>>& dominoes) { 
        int n = dominoes.size();

        map<int , int> mpp;

        int ans = 0;

        for(int i=0; i<n; i++){
            vector<int> temp = dominoes[i];

            int a = temp[0] * 10;
            int num = a + temp[1];

            if(mpp.find(rev(num)) != mpp.end()){
                mpp[rev(num)]++;
            }
            else {
                mpp[num]++;
            }
        }

        for(auto it : mpp){
            ans += ((it.second) * (it.second - 1)) / 2;
        }
        return ans;
    }
};