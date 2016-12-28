class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0)
            return 0;
        unordered_map<char, int> used;
        int maxLen = 0;
        for(int i = 0, j = 0; j < s.length(); ){//[i,j)
            if(used.size() >= k && used.find(s[j]) == used.end()){
                while(used.size() >= k && i < j){
                    if(--used[s[i]] == 0)
                        used.erase(s[i]);
                    i++;
                }
            }
            used[s[j++]]++;
            maxLen = max(maxLen, j-i);
        }
        return maxLen;
    }
};