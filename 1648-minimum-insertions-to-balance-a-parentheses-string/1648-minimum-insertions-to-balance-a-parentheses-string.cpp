// class Solution {
// public:
//     int minInsertions(string s) {
//         int n = s.size();

//         int insertions = 0;
//         int open = 0;

//         for(int i=0; i<n; i++){
//             if(s[i] == '('){
//                 open++;
//             }
//             else if(s[i] == ')'){
//                 if(i < n-1 && s[i+1] == ')'){
//                     if(open > 0){
//                         open--;
//                     }
//                     else {
//                         insertions++;
//                     }
//                     i++;
//                 }
//                 else {
//                     if(open > 0){
//                         open--;
//                         insertions++;
//                     }
//                     else if(open == 0){
//                       insertions += 2;  
//                     }
//                 }
//             }
//         }
//         return insertions + (open * 2);
//     }
// };







class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        int insertions = 0;
        int open = 0;

        for(int i=0; i<n; i++){
            //cnt opening bracket
            if(s[i] == '('){
                open++;
            }
            //if i get closing bracket
            else if(s[i] == ')'){
                //if i get two consecutive closing bracket
                if(i < n-1 && s[i+1] == ')'){
                    //look for an opening bracket before
                    if(open > 0){
                        //if present pair it
                        open--;
                    }
                    else {
                        //otherwise we need to insert an opening bracket
                        insertions++;
                    }
                    //skip idx and move to next one as there we two consectutive closing brackets
                    i++;
                }
                //if we having opening bracket after closing bracket
                else {
                    //we need to insert an closing bracket as we want two closing bracket
                    insertions++;

                    //then check same two conditions
                    //if we have opening bracket before
                    if(open > 0){
                        //pair it with two consecutive closing brackets
                        open--;
                    }
                    else {
                        //otherwise add an opening bracket
                        insertions++;
                    }
                }
            }
        }
        //final answer will be insertions cnt + if we have x opening brackets left so we have to add 2*x brackets (closing)
        return insertions + (open * 2);
    }
};