class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();

        int cnt = 0;

        if(colors[0] != colors[1] && colors[0] != colors[n-1]) cnt++;

        if(colors[n-1] != colors[n-2] && colors[n-1] != colors[0]) cnt++;

        for(int i=1; i<n-1; i++){
            if(colors[i] != colors[i-1] && colors[i] != colors[i+1]) cnt++;
        }
        return cnt;
    }
};