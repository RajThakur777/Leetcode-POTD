class Solution 
{
public:
    int lengthAfterTransformations(string s, int t) 
    {
        const int M = 1'000'000'007;
        vector<int> map(26, 0);

        // Step 1: Count frequency of each character
        for(char c : s) 
        {
            map[c - 'a']++;
        }

        // Step 2: Perform t transformations
        for(int count = 1; count <= t; count++) 
        {
            vector<int> temp(26, 0);
            for(int i = 0; i < 26; i++) 
            {
                char c = i + 'a';
                int f = map[i];

                if(c != 'z') 
                {
                    temp[(c + 1) - 'a'] = (temp[(c + 1) - 'a'] + f) % M;
                } 
                else 
                {
                    temp['a' - 'a'] = (temp['a' - 'a'] + f) % M;
                    temp['b' - 'a'] = (temp['b' - 'a'] + f) % M;
                }
            }

            map = temp;
        }

        // Step 3: Sum all character counts
        int result = 0;
        for(int i = 0; i < 26; i++) 
        {
            result = (result + map[i]) % M;
        }

        return result;
    }
};