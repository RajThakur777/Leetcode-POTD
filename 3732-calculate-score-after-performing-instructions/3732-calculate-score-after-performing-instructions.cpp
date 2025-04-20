class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();

        long long ans = 0;

        int i = 0;

        vector<bool> vis(n , false);

        while(i >= 0 && i < n && !vis[i]){
            vis[i] = true;

            if(instructions[i] == "add"){
                ans += values[i];
                i++;
            }
            else if(instructions[i] == "jump"){
                i += values[i];
            }
        }   
        return ans;
    }
};