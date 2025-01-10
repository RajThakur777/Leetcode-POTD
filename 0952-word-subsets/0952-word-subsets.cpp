class Solution {
public:

    void setMax(vector<int> &max_freq , vector<int> &freq1){
        for(int i=0; i<26; i++){
            max_freq[i] = max(max_freq[i] , freq1[i]);
        }
    }

    bool isUniversal(vector<int> &max_freq , vector<int> &freq2){ 
        for(int i=0; i<26; i++){
            if(max_freq[i] > freq2[i]){
                return false;
            }
        }    
        return true;
    }
 
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words2.size();

        vector<string> ans;

        vector<int> max_freq(26);
        for(int i=0; i<n; i++){
            vector<int> freq1(26);
            string temp2 = words2[i];

            for(int j=0; j<temp2.size(); j++){
                freq1[temp2[j] - 'a']++;
            }
            setMax(max_freq , freq1);
        }
        
        for(int i=0; i<words1.size(); i++){
            vector<int> freq2(26);

            string temp1 = words1[i];

            for(int j=0; j<temp1.size(); j++){
                freq2[temp1[j] - 'a']++;
            }

            if(isUniversal(max_freq , freq2)){
                ans.push_back(temp1);
            }
        }
        return ans;
    }
};