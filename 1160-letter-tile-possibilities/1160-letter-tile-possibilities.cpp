//Recursion + Backtracking:
class Solution {
public:

    void helper(string tiles , unordered_set<string> &st , string curr , vector<bool> &used){
        st.insert(curr);

        for(int i=0; i<tiles.size(); i++){
            if(!used[i]){
                used[i] = true;
                helper(tiles , st , curr + tiles[i] , used);
                used[i] = false;
            }
        }
    }

    int numTilePossibilities(string tiles) { 
        unordered_set<string> st;

        vector<bool> used(tiles.size()+1 , false);

        helper(tiles , st , " " , used);

        return st.size() - 1; 
    }
};