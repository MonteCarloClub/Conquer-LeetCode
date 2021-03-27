class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, length = s.length(), ans = 0;
        auto duplicate = unordered_set<char>();
        for(;i<length;++i) {
            while(j<length&&!duplicate.count(s[j])) {    
                duplicate.insert(s[j]);
                ++j;
            }
            ans = max(ans, j-i);
            duplicate.erase(s[i]);
        }
        return ans;
    }
};