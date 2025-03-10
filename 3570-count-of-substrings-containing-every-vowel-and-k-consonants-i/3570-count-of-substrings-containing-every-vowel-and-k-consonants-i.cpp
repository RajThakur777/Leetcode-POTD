// class Solution {
// public:
//     int countOfSubstrings(string word, int k){
//         int n = word.size();
//         int cnt = 0;

//         for (int i = 0; i < n; i++) {
//             set<char> st;
//             int consonent = 0;
//             for (int j = i; j < n; j++) {
//                 if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u') {
//                     st.insert(word[j]);
//                 }
//                 else {
//                     consonent++;
//                 }

//                 if(st.size() >= 5 && consonent == k){
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };






class Solution {
public: 
int countOfSubstrings(string s, int k) {
    int ans = 0;

    for(int i=0;i<s.size();i++){
        int a=0, e=0, m=0, o=0,u=0,c=0; 
        for(int j=i;j<s.size();j++){
            if(s[j]=='a') a++;
            else if(s[j]=='e') e++;
            else if(s[j]=='i') m++;
            else if(s[j]=='o') o++;
            else if(s[j]=='u') u++;
            else c++;  

            if(a and e and m and o and u and c==k) ans++;
        }
    }
        
    return ans;
}
};