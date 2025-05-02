//Implementation Based Question:
class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size(); 

        int right = -1;
        for(int i=0; i<n; i++){
            if(s[i] == 'L'){
                if(right == -1){
                    for(int j=i-1; j>=0 && s[j] == '.'; j--){
                        s[j] = 'L';
                    }
                }
                else {
                    int j = right + 1;
                    int k = i - 1;

                    while(j < k){
                        s[j++] = 'R';
                        s[k--] = 'L';
                    }
                    right = -1;
                }
            }
            else if(s[i] == 'R'){
                if(right != -1){
                    for(int j=right + 1; j<i; j++){
                        s[j] = 'R';
                    }
                }
                right = i;
            }
        }
        if(right != -1){
            for(int j=right + 1; j<n; j++){
                s[j] = 'R';
            }
        }
        return s;
    }
};