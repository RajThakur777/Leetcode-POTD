class Solution {
public:
    bool canChange(string start, string target) {
        int m = start.size();
        int n = target.size();

        int i = 0;
        int j = 0;

        while(i < m || j < n){
            while(i < m && start[i] == '_'){
                i++;
            }

            while(j < n && target[j] == '_'){
                j++;
            }

            if(i == m || j == n){
                return (i == m && j == n);
            }

            if(start[i] != target[j] || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};