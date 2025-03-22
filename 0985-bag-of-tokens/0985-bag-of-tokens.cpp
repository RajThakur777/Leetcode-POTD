class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
         int score=0 , maxscore=0;
        sort(tokens.begin() , tokens.end());
        int i=0 , j=tokens.size()-1;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                maxscore = max(maxscore , score);
                power  -= tokens[i];
                i++; 
            }

            else if(score>0){
                power += tokens[j];
                score--;
                j--;
            }

            else break;
            
        }
        return maxscore;
    }
};