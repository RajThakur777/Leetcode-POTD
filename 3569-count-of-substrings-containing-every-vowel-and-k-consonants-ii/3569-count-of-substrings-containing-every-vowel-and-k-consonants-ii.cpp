// class Solution {
// public:
//     long long countOfSubstrings(string word, int k) {    
//         int n = word.size(); 

//         int ans = 0;

//         for(int i=0;i<word.size();i++){
//             int a=0, e=0, m=0, o=0,u=0,c=0; 
//             for(int j=i;j<word.size();j++){
//               if(word[j]=='a') a++;
//               else if(word[j]=='e') e++;
//               else if(word[j]=='i') m++;
//               else if(word[j]=='o') o++;
//               else if(word[j]=='u') u++;
//               else c++;  

//               if(a and e and m and o and u and c==k) ans++;
//             }
//         }    
//         return ans;   
//     }
// };






class Solution {
public:
    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.length();

        unordered_map<char, int> mp; //to keep count of vowels in a current window
        //S.C : O(5) constant

        //Preprocessing to be able to find index of just next consonant
        vector<int> nextCons(n); //S.C : O(n)
        int lastConsIdx = n;
        //T.C : O(n)
        for(int i = n-1; i >=0; i--) {
            nextCons[i] = lastConsIdx;
            if(!isVowel(word[i])) { //consonant
                lastConsIdx = i;
            }
        }


        int i = 0;
        int j = 0;
        long long count = 0;
        int cons = 0;
        //T.C : O(2*n) ~ O(n) 
        while(j < n) {
            char ch = word[j];
            if(isVowel(ch)) {
                mp[ch]++;
            } else {
                cons++;
            }

            //cons must be always == k
            while(cons > k) {
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            while(i < n && mp.size() == 5 && cons == k) { //valid window
                int idx = nextCons[j]; //it will tell me the next consonant after jth index
                count += idx - j; //most important part
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            j++;
        }

        return count;
    }
};

