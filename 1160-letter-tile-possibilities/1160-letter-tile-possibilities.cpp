//Recursion + Backtracking:
// class Solution {
// public:

//     void helper(string tiles , unordered_set<string> &st , string curr , vector<bool> &used){
//         st.insert(curr);

//         for(int i=0; i<tiles.size(); i++){
//             if(!used[i]){
//                 used[i] = true;
//                 helper(tiles , st , curr + tiles[i] , used);
//                 used[i] = false;
//             }
//         }
//     }

//     int numTilePossibilities(string tiles) { 
//         unordered_set<string> st;

//         vector<bool> used(tiles.size()+1 , false);

//         helper(tiles , st , " " , used);

//         return st.size() - 1; 
//     }
// };






//Recursion + Backtracking:
class Solution {
public:

    void helper(string tiles , string curr , unordered_set<string> &st , vector<bool> &used){
        st.insert(curr);

        for(int i=0; i<tiles.size(); i++){
            if(used[i] == true){
                continue;
            }
            used[i] = true;
            helper(tiles , curr + tiles[i] , st , used);
            used[i] = false;
        }
    }

    int numTilePossibilities(string tiles) { 
        int n = tiles.size();

        unordered_set<string> st;

        vector<bool> used(n+1 , false);

        helper(tiles , " " , st , used);

        return st.size() - 1;
    }
};