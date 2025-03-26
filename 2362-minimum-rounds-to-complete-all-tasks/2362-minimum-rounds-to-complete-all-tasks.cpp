class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();

        int ans = 0;

        map<int , int> mpp;
        for(int i=0; i<n; i++){
            mpp[tasks[i]]++;
        }

        bool flag = true;
        for(auto it : mpp){
            if(it.second < 2){
                flag = false;
                break;
            }
        }

        if(!flag) return -1;

        int cnt = 0;
        for(auto it : mpp){
            if(it.second == 2){
                cnt++;
            }
            else {
                cnt += (it.second + 2) / 3;
            }
        }
        return cnt;
    }
};