//Recursion:
class Solution {
public:
    int n;

    int solve(int idx , vector<string> &arr , set<char> st) {
        if(idx >= arr.size()) {
            return st.size();
        }

        bool flag = true;
        string str = arr[idx];
        set<char> temp = st;

        for(int i=0; i<str.size(); i++) {
            if(temp.find(str[i]) != temp.end()) {
                flag = false;
                break;
            }
            else {
                temp.insert(str[i]);
            }
        }

        int pick = 0;
        int not_pick = 0;

        if(flag) {
            pick = solve(idx+1 , arr , temp);
        }

        not_pick = solve(idx+1 , arr , st);

        return max(pick , not_pick);
    }

    int maxLength(vector<string>& arr) {
        n = arr.size();

        set<char> st;

        return solve(0 , arr , st);
    }
};