class Solution {
public:
    int maxi ;
    int mini ;

    void solve(int n, int firstPlayer, int secondPlayer,int index1,int index2,int round,int state){
        if(index1>=index2){
            solve(n,firstPlayer,secondPlayer,1,n,round+1,state);
            return;
        }
        else if(((1<<index1) & state)==0){
            solve(n,firstPlayer,secondPlayer,index1+1,index2,round,state);
            return;
        }
        else if(((1<<index2) & state)==0){
            solve(n,firstPlayer,secondPlayer,index1,index2-1,round,state);
            return;
        }
        else if((index1==firstPlayer && index2==secondPlayer) || (index1 == secondPlayer && index2 == firstPlayer)){
            
            maxi = max(maxi,round);
            mini = min(mini,round);
            return;
        }
        else{
            if(index1!=firstPlayer && index1!=secondPlayer){
                solve(n,firstPlayer,secondPlayer,index1+1,index2-1,round,(state ^ (1<<index1)));
                
            }
            if(index2!=firstPlayer && index2!=secondPlayer){
                 solve(n,firstPlayer,secondPlayer,index1+1,index2-1,round,(state ^ (1<<index2)));
            }
            return;
        }

    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        maxi = 0;
        mini = INT_MAX;

        solve(n,firstPlayer,secondPlayer,1,n,1,(1<<(n+2))-1);
        return {mini,maxi};
    }
};