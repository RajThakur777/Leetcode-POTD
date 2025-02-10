// class Solution {
// public:

//     bool isDigit(char ch){
//         if(ch >= '0' && ch <= '9'){
//             return true;
//         }
//         return false;
//     }

//     bool isCharacter(char ch){
//         if(ch >= 'a' && ch <= 'z'){
//             return true;
//         }
//         return false;
//     }

//     string clearDigits(string s) {
//         int n = s.size();

//         string ans;

//         vector<int> mark(n , -1);
//         for(int i=0; i<n; i++){
//             if(isDigit(s[i])){
//                 mark[i] = 0;
//                 for(int j=i-1; j>=0; j--){
//                     if(isCharacter(s[j]) && mark[j] != 0){
//                         mark[j] = 0;
//                         break;
//                     }
//                 }
//             }
//         }
//         for(int i=0; i<n; i++){
//             if(mark[i] == -1){
//                 ans += s[i];
//             }
//         }
//         return ans;
//     }
// };




//using stack:
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                if(!st.empty()){
                    st.pop();
                }
            }
            else {
                st.push(s[i]);
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};