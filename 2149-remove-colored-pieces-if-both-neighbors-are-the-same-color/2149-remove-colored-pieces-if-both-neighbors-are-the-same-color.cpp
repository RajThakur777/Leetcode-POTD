class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();

        if(n < 3) return false;

        int alice = 0;
        int bob = 0;

        for(int i=1; i<n-1; i++){
            if(colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A'){
                alice++;
            }
            else if(colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B'){
                bob++;
            }
        }

        if(alice > bob){
            return true;
        }
        else if(bob > alice){
            return false;
        }
        return false;
    }
};